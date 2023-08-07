#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Function to output a string of characters to stdout
int ra_put_string(char *s);

// Function to output a single character to stdout
int rawlin_put_char(char c)
{
    return write(1, &c, 1);
}

// Function to convert a void pointer to its hexadecimal representation and output it to stdout
int digits_point(void *pvalue)
{
    unsigned long case_p = (unsigned long)pvalue;
    int i = 0, height = 0;
    char horz_put[64];
    do
    {
        unsigned long min = case_p % 16;
        horz_put[i++] = (min < 10) ? min + '0' : min + 'a' - 10;
        case_p /= 16;
    } while (case_p != 0);
    height = ra_put_string("0x"); // Output "0x" before the hexadecimal representation
    while (i-- > 0) // Output each hexadecimal digit
    {
        rawlin_put_char(horz_put[i]);
        height++;
    }
    return height;
}

// Function to convert an unsigned integer to a given base and output it to stdout
int ra_digits_int(unsigned int nbr, char *base, int base_size)
{
    int count = 0;
    if (nbr >= (unsigned int)base_size)
    {
        count += ra_digits_int(nbr / base_size, base, base_size); // Recursively output the remaining digits
    }
    count += rawlin_put_char(base[nbr % base_size]); // Output the least significant digit
    return count;
}

// Function to convert an integer to its decimal representation and output it to stdout
int case_digits(int nbr)
{
    int count = 0;
    if (nbr < 0)
    {
        count += rawlin_put_char('-'); // Output a minus sign for negative numbers
        nbr = -nbr; // Convert the number to its absolute value
    }
    if (nbr >= 10)
    {
        count += case_digits(nbr / 10); // Recursively output the remaining digits
    }
    count += rawlin_put_char(nbr % 10 + '0'); // Output the least significant digit
    return count;
}

// Function to output a string of characters to stdout
int ra_put_string(char *s)
{
    int len = 0;
    while (*s != '\0') { // Output each character in the string
        rawlin_put_char(*s++);
        len++;
    }
    return len;
}

/*

The my_printf function is a custom implementation of the standard printf function in C. It takes a format string
 and a variable number of arguments and prints formatted output to the console. It supports various format specifiers
  for different data types and formatting options, such as integers, characters, strings, and pointers. The function uses
   the va_list macro and the va_arg function to extract the arguments from the variable argument list.
*/

int my_printf(char *restrict fmt, ...)
{
    va_list args_list; // Initialize variable arguments
    va_start(args_list, fmt);  // Start traversing variable arguments
    int num_chars_written =
        0;  // Initialize counter for number of characters written
    for (int i = 0; fmt[i] != '\0';
         i++)  // Loop through each character in the format string
    {
        if (fmt[i] ==
            '%')  // Check if the current character is a format specifier
        {
            i++; // Move to the next character after the '%'
            switch (fmt[i])  // Check the format specifier character
            {
                case 'd': // Integer format specifier
                {
                    num_chars_written += case_digits(va_arg(
                        args_list, int));  // Call function to print the integer
                                           // value and add the number of
                                           // characters written to the counter
                    break;
                }
                case 'o': // Octal format specifier
                {
                    unsigned int i = va_arg(args_list, unsigned int); // Get the unsigned integer value from variable arguments
                    num_chars_written += ra_digits_int(
                        i, "01234567",
                        8);  // Call function to print the octal value and add
                             // the number of characters written to the counter
                    break;
                }
                case 'u': // Unsigned integer format specifier
                {
                    unsigned int i = va_arg(args_list, unsigned int); // Get the unsigned integer value from variable arguments
                    num_chars_written += ra_digits_int(
                        i, "0123456789",
                        10);  // Call function to print the unsigned integer
                              // value and add the number of characters written
                              // to the counter
                    break;
                }
                case 'x': // Hexadecimal format specifier
                {
                    unsigned int i = va_arg(args_list, unsigned int); // Get the unsigned integer value from variable arguments
                    num_chars_written += ra_digits_int(
                        i, "0123456789ABCDEF",
                        16);  // Call function to print the hexadecimal value
                              // and add the number of characters written to the
                              // counter
                    break;
                }
                case 'c': // Character format specifier
                {
                    char c = (char)va_arg(args_list, int); // Get the character value from variable arguments
                    write(1, &c, 1); // Write the character to standard output
                    num_chars_written++;  // Add 1 to the counter for number of
                                          // characters written
                    break;
                }
                case 's': // String format specifier
                {
                    char *s = va_arg(args_list, char *); // Get the string value from variable arguments
                    int cwritten = 0; // Initialize a counter for number of characters written for the string
                    if (s == NULL) // If the string is NULL, print "(null)"
                    {
                        cwritten = ra_put_string("(null)");
                    }
                    else // Otherwise, print the string
                    {
                        cwritten = ra_put_string(s);
                    }
                    num_chars_written +=
                        cwritten;  // Add the number of characters written for
                                   // the string to the counter
                    break;
                }
                case 'p': // Pointer format specifier
                {
                    void *p = va_arg(args_list, void *); // Get the pointer value from variable arguments
                    num_chars_written += digits_point(
                        p);  // Call function to print the pointer value in
                             // hexadecimal and add the number of characters
                             // written to the counter
                    break;
                }
                default: // If the format specifier is invalid, print the character as is
                {
                    char c = *fmt;
                    write(1, &c, 1);
                    num_chars_written++;
                    break;
                }
            }
        }
        else // If the current character is not a format specifier, print it as is
       

        {
            num_chars_written += rawlin_put_char(fmt[i]);
        }
    }

    return num_chars_written;
}


/*
The code implements a simplified
 version of the printf function called my_printf. It supports basic format specifiers such
  as %d, %o, %u, %x, %c, %s, and %p, and handles printing of integers, octal, unsigned integers,
 hexadecimal, characters, strings, and pointers. The code iterates through the format string, detects format
  specifiers, and processes the corresponding arguments to print the desired output.
  */
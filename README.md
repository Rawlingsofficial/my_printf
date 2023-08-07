# Welcome to My Printf
The my_printf function is a custom implementation of the standard printf function in C. It takes a format string
 and a variable number of arguments and prints formatted output to the console. It supports various format specifiers
  for different data types and formatting options, such as integers, characters, strings, and pointers. The function uses
   the va_list macro and the va_arg function to extract the arguments from the variable argument list.

## Task
 What is the problem? And where is the challenge?
 doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
p The void * pointer argument is printed in hexadecimal.

## Description
This code defines several functions to output data to standard output. Specifically, it includes functions to output strings, single characters, decimal and hexadecimal representations of integers, and hexadecimal representations of void pointers.
 These functions use recursive algorithms to output the individual digits of each number or character in the correct order. The main my_printf function uses these functions to format and output data according to the provided format string.

## Installation
there is no was instalation for this project

## Usage
How does it work?

The code provided implements a custom version of the printf() function in C, named my_printf(). The function takes a format string and a variable number of arguments and prints formatted output to the console. It supports various format specifiers for different data types and formatting options, such as integers, characters, strings, and pointers.

The function uses the va_list macro and the va_arg function to extract the arguments from the variable argument list. Inside the function, there are multiple helper functions that are responsible for formatting and outputting the various data types.

The ra_digits_int() function is responsible for converting an unsigned integer to a given base and outputting it to stdout. The function takes an unsigned integer, a string representing the base, and the size of the base as arguments. The function uses recursion to output each digit in the correct order.

The case_digits() function is responsible for converting an integer to its decimal representation and outputting it to stdout. The function takes an integer as an argument and uses recursion to output each digit in the correct order. If the number is negative, it outputs a minus sign before the absolute value.

The digits_point() function is responsible for converting a void pointer to its hexadecimal representation and outputting it to stdout. The function takes a void pointer as an argument and uses a loop to extract each hexadecimal digit from the pointer's value.

The ra_put_string() function is responsible for outputting a string of characters to stdout. The function takes a character pointer as an argument and uses a loop to output each character in the string.

The my_printf() function loops through each character in the format string and checks if the current character is a format specifier. If the current character is a format specifier, it uses a switch statement to determine the type of data to output and calls the appropriate helper function to format and output the data. The function keeps track of the number of characters written to stdout and returns that value.
```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>

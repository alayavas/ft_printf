# ft_printf

A custom implementation of the printf function in C, recreating the behavior of the standard library printf function with support for various format specifiers.

## Description

This project implements a custom printf function (`ft_printf`) that mimics the behavior of the standard C library printf function. It supports multiple format specifiers and handles various data types for formatted output.

## Features

### Supported Format Specifiers

- `%c` - Character
- `%s` - String
- `%p` - Pointer address (hexadecimal format with 0x prefix)
- `%d` - Signed decimal integer
- `%i` - Signed integer
- `%u` - Unsigned decimal integer
- `%x` - Unsigned hexadecimal (lowercase)
- `%X` - Unsigned hexadecimal (uppercase)
- `%%` - Literal percent sign

### Key Functions

- **ft_printf()** - Main printf implementation
- **ft_print_char()** - Prints a single character
- **ft_print_str()** - Prints a string
- **ft_print_ptr()** - Prints pointer addresses
- **ft_print_int()** - Prints signed integers
- **ft_print_uint()** - Prints unsigned integers
- **ft_print_hex()** - Prints hexadecimal numbers
- **ft_putnbr_base()** - Prints numbers in specified base
- **ft_strlen()** - Calculates string length

## File Structure

```
├── ft_printf.h          # Header file with function declarations
├── ft_printf.c          # Main printf implementation
├── ft_printf_func.c     # Format-specific printing functions
├── ft_utils.c           # Utility functions
└── Makefile            # Build configuration
```

## Compilation

The project includes a Makefile for easy compilation:

```bash
# Compile the library
make

# Clean object files
make clean

# Clean all generated files
make fclean

# Recompile everything
make re
```

### Compilation Flags

- `-Wall` - Enable all common warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

## Usage

1. Include the header file in your C program:
```c
#include "ft_printf.h"
```

2. Compile your program with the library:
```bash
gcc your_program.c libftprintf.a -o your_program
```

3. Use ft_printf in your code:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\
", "World");
    ft_printf("Number: %d\
", 42);
    ft_printf("Hex: %x\
", 255);
    ft_printf("Pointer: %p\
", &main);
    return (0);
}
```

## Implementation Details

### Error Handling
- Returns -1 on write errors
- Handles NULL string pointers by printing "(null)"
- Handles NULL pointers by printing "(nil)"

### Memory Management
- No dynamic memory allocation used
- All operations use stack-based variables
- Safe handling of edge cases like INT_MIN

### Base Conversion
The `ft_putnbr_base()` function supports printing numbers in different bases:
- Decimal (base 10): "0123456789"
- Hexadecimal lowercase (base 16): "0123456789abcdef"
- Hexadecimal uppercase (base 16): "0123456789ABCDEF"

## Return Value

The `ft_printf` function returns the number of characters printed, or -1 if an error occurs during writing.

## Limitations

This implementation focuses on the core functionality of printf and may not include all advanced features of the standard library version, such as:
- Field width specifiers
- Precision specifiers
- Flag modifiers (-, +, #, 0, space)
- Length modifiers (l, ll, h, hh)

## Author

Created by alyavas for 42 School project.
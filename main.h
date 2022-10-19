#ifndef MAIN.H
#define MAIN.H
#define INT_BYTS (8 * 4)

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct call
{
	char t;
	int (*f)(char *, va_list, int);
} call_t;

int int_func(char *buff_dest, va_list list, int buff_count);
int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int hexidec_func(char *buff_dest, va_list arg, int buff_count);
int printf_oct(va_list val);
int octal_func(char *buff_dest, va_list arg, int buff_count);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int binary_func(char *buff_dest, va_list arg, int buff_count);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int sign_func(char *buff_dest, va_list arg, int buff_count);
int printf_int(va_list args);
int printf_dec(va_list args);
int other_func(char *buff_dest, va_list arg, int buff_count);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int unint_func(char *buff_dest, va_list arg, int buff_count);
int _printf(const char *format, ...);

#endif

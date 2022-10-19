#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, buff_count = 0, prev_buff_count = 0;
	char buffer[2000];
	va_list arg; /*this is for the arguments*/
	call_t container[] = { /* container for other functions */
		{'c', char_func}, {'s', charS_func}, {'i', int_func}, {'d', int_func},
		{'%', sign_func}, {'b', binary_func}, {'o', octal_func}, {'x', hexidec_func},
		{'X', other_func}, {'u', unint_func}, {'R', R_func}, {'r', rev_func},
		{'\0', NULL}
	};

	if (!format) /* in the event there isn't an argument*/
		return (-1); /* for error*/
	va_start(arg, format);
	while (format && format[i] != '\0') /* While there is an argument*/
	{
		if (format[i] == '%') /* check if we have that “%” sign */
		{
			i++;
			prev_buff_count = buff_count; /*this will be for the later one, kinda like making it catch up */
			for (j = 0; container[j].t != '\0'; j++) /*this loop will loop through till we reach the null character*/
			{
				/* self explaining */
				if (format[i] == '\0') 
					break;
				if (format[i] == container[j].t)
				{
					buff_count = container[j].f(buffer, arg, buff_count);
					break;
				}
			}
			if (buff_count == prev_buff_count && format[i])
				i--, buffer[buff_count] = format[i], buff_count++;
		}
		else
			buffer[buff_count] = format[i], buff_count++;
		i++;
	}
	va_end(arg);
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count);
	return (buff_count);
}

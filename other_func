#include "main.h"

/**
 * parse_perc - returns the character
 * @buff_dest: character
 * @arg: list of arguments
 * @buff_count: index of buffer pointer
 * Return: the buffer index
 */
int sign_func(char *buff_dest, va_list arg, int buff_count)
{
	char c = va_arg(arg, int);

	/* reassigned due to unexpected behaviour */
	c = '%';

	buff_dest[buff_count] = c;

	return (++buff_count);
}

int other_func(char *buff_dest, va_list arg, int buff_count)
{
	unsigned int number = va_arg(arg, unsigned int);
	unsigned int tmp = number;
	int hex = 1;

	while (tmp > 15)
	{
		hex *= 16;
		tmp /= 16;
	}

	tmp = number;
	while (hex > 0)
	{
		buff_dest[buff_count] = (tmp / hex < 9) ?
			(tmp / hex + '0') : ('A' + tmp / hex - 10);
		tmp %= hex;
		hex /= 16;
		buff_count++;
	}

	return (buff_count);
}

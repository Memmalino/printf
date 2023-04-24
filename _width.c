#include "main.h"

/**
 * get_width - check the width of argument to print
 * @format: Format for printing the argument.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int b;
	int width = 0;

	for (b = *i + 1; format[b] != '\0'; b++)
	{
		if (is_digit(format[b]))
		{
			width *= 10;
			width += format[b] - '0';
		}
		else if (format[b] == '*')
		{
			b++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = b - 1;

	return (width);
}


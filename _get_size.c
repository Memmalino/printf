#include "main.h"

/**
 * get_size - This function calculates the size
 * to cast the argument
 * @format: Formatted string in which to print the arguments
 * @a: This is the list of arguments to be printed.
 *
 * Return: Precision.
 */

int get_size(const char *format, int *a)
{
	int curr_a = *a + 1;
	int size = 0;

	if (format[curr_a] == 'l')
		size = S_LONG;
	else if (format[curr_a] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = curr_a - 1;
	else
		*a = curr_a;

	return (size);
}


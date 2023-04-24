#include "main.h"

/* Printing an Unsigned Number */

/**
 * print_unsigned - This function prints an unsigned number
 * @types: This prints the List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:   This calculates  the active flags
 * @width: get width
 * @precision: Precision specification
 * @size:  This represents the size specifier
 * Return: This is the number of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* Printing an unsigned Number in octal */

/**
 * print_octal - This function prints an unsigned number in octal notation
 * @types: This is the list of arguments
 * @buffer: Buffer array to handle print
 * @flags: This  calculates the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: This is the size specifier
 * Return: This is the number of chars printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* Printing an Unsigned Number in Hexadecimal */

/**
 * print_hexadecimal - This function prints an unsigned
 * number in hexadecimal notation
 * @types: This is the list  of arguments
 * @buffer: Buffer array to handle print
 * @flags:  This calculates the  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: This represents the size specifier
 * Return: this represents the number of chars printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* Printing an Unsigned Number in Upper Hexa decimal */

/**
 * print_hexa_upper -  This function prints an unsigned number
 * in upper hexadecimal notation
 * @types:  This is the List of arguments
 * @buffer: Buffer array to handle print
 * @flags:   This calculates the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: This represents the size specifier
 * Return: This represents the number of chars printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* Printing a Hexadecimal num in Lower or Upper */

/**
 * print_hexa - This function prints a hexadecimal number in lower or upper
 * @types:  This is the list of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:   This calculates the  active flags
 * @flag_ch: this calculates the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: This represents the size specifier
 * @size: Size specification
 * Return: This is the number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

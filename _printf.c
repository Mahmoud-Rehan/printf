#include "main.h"

void print_int(int n);

/**
 * _printf - Function works like printf.
 * @format: The formated string.
 * Return: The length.
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	int i = 0;
	int n;
	char *s;
	char c;

	if (format == NULL)
	{
		return (-1);
	}

	va_list args;

	va_start(args, format);

	while (format[i])
	{
		counter++;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				break;
			}

			switch (format[i])
			{
				case 'i':
				case 'd':
				{
					n = va_arg(args, int);
					print_int(n);
					break;
				}
				case 'c':
				{
					c = va_arg(args, int);
					putchar(c);
					break;
				}
				case 's':
				{
					s = va_arg(args, char *);
					while (*s)
					{
						putchar(*s);
						s++;
					}
					break;
				}
				case '%':
					putchar('%');
					break;
				default:
					putchar(format[i]);
					break;
			}
		}
		else
		{
			putchar(format[i]);
		}
		i++;
	}

	va_end(args);

	return (counter);
}

/**
 * print_int - Print integers.
 * @n: The printed value.
 */

void print_int(int n)
{
	int i;
	char buffer[30];
	int value = snprintf(buffer, sizeof(buffer), "%d", n);

	for (i = 0; i < value; i++)
	{
		putchar(buffer[i]);
	}
}

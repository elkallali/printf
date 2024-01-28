#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf -  A custom implementation of the printf
 * function that handles the conversion specifiers 'c', 's', and '%'.
 * @format: The format string, which is composed of zero or more directives.
 * @...: The variable arguments.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 *
 * This function handles the following conversion specifiers:
 * - %c: A character.
 * - %s: A string.
 * - %: A percent sign.
 *
 * It doesn't handle the flag characters,
 * field width, precision, and length modifiers.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
			{
				char c = (char) va_arg(args, int);

				putchar(c);
				count++;
				break;
			}
			case 's':
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s);
					count++;
					s++;
				}
				break;
			}
			case '%':
			{
				putchar('%');
				count++;
				break;
			}
			default:
			{
				putchar('%');
				putchar(*format);
				count += 2;
				break;
			}
			}
			format++;
		}
	}
	va_end(args);
	return (count);
}


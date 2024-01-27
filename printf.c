#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            count++;
        } else {
            format++;
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s) {
                        putchar(*s);
                        count++;
                        s++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    // Unsupported format specifier, print it as is
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
    return count;
}


#include "main.h"

/**
 * get_precision - Extracts the precision from a format string.
 *
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 * @list: The argument list.
 *
 * Returns: The precision value, or -1 if no precision is specified.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int precision = -1;

    /* Check if precision is specified */
    if (format[*i] == '.' && is_digit(format[*i + 1])) {
        /* Parse precision value */
        precision = 0;
        while (is_digit(format[*i + 1])) {
            precision = precision * 10 + format[++(*i)] - '0';
        }
    } else if (format[*i] == '.' && format[*i + 1] == '*') {
        /* Precision is passed as an argument */
        ++(*i);
        precision = va_arg(list, int);
    }

    return precision;
}

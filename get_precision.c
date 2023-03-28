#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: Precision
 */

#include <stdarg.h>

/**
 * get_precision - Calculates the precision for printing.
 *
 * @format: The format string.
 * @i: A pointer to the current index in the format string.
 * @...: The variable arguments.
 *
 * Returns: The precision.
 */
int get_precision(const char *format, int *i, ...)
{
    va_list args;
    int curr_i = *i + 1;
    int precision = -1;

    va_start(args, i);

    if (format[curr_i] != '.') {
        va_end(args);
        return precision;
    }

    precision = 0;

    curr_i++;
    if (format[curr_i] == '*') {
        precision = va_arg(args, int);
        curr_i++;
    } else {
        while (format[curr_i] >= '0' && format[curr_i] <= '9') {
            precision = (precision * 10) + (format[curr_i] - '0');
            curr_i++;
        }
    }

    *i = curr_i - 1;

    va_end(args);

    return precision;
}

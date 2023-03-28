#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int precision = -1;

    if (format[*i] == '.')
    {
        *i += 1;

        if (format[*i] == '*')
        {
            *i += 1;
            precision = va_arg(list, int);
        }
        else
        {
            precision = 0;

            while (isdigit(format[*i]))
            {
                precision = 10 * precision + (format[*i] - '0');
                *i += 1;
            }
        }
    }

    return precision;
}


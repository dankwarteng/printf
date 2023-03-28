#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: Precision
 */

int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;
    int state = 0;

    while (format[curr_i] != '\0')
    {
        switch (state)
        {
            case 0:  // initial state
                if (format[curr_i] == '.')
                {
                    state = 1;
                    precision = 0;
                }
                else
                {
                    state = 2;
                }
                break;

            case 1:  // parsing precision
                if (is_digit(format[curr_i]))
                {
                    precision = precision * 10 + (format[curr_i] - '0');
                }
                else if (format[curr_i] == '*')
                {
                    precision = va_arg(list, int);
                    state = 2;
                }
                else
                {
                    state = 2;
                    *i = curr_i - 1;
                    return precision;
                }
                break;

            case 2:  // done parsing
                *i = curr_i - 1;
                return precision;
        }

        curr_i++;
    }

    *i = curr_i - 1;
    return precision;
}

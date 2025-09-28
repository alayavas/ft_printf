/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyavas <alyavas@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:29:06 by alyavas           #+#    #+#             */
/*   Updated: 2025/09/28 16:55:32 by alyavas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static int	ft_format_selector(char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_percent());
	return (-1);
}

static int	ft_print_format(const char *format, int *i, va_list args)
{
	char	next_char;

	next_char = format[*i + 1];
	if (next_char == '\0')
		return (-1);
	else if (ft_is_specifier(next_char))
	{
		(*i)++;
		return (ft_format_selector(next_char, args));
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;
	int		stack_len;

	if (!format)
		return (-1);
	va_start(args, format);
	total_len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			stack_len = ft_print_format(format, &i, args);
			if (stack_len == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
		{
			stack_len = write(1, &format[i], 1);
			if (stack_len == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		total_len += stack_len;
		i++;
	}
	va_end(args);
	return (total_len);
}


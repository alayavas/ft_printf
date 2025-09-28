/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyavas <alyavas@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:29:06 by alyavas           #+#    #+#             */
/*   Updated: 2025/09/28 16:55:56 by alyavas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[len])
	{
		if (ft_print_char(str[len]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	len += ft_putnbr_base(ptr, "0123456789abcdef");
	if (len < 2)
		return (-1);
	return (len);
}

int	ft_print_int(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		if (n == -2147483648)
			return (len + ft_putnbr_base(2147483648, "0123456789"));
		n = -n;
	}
	len += ft_putnbr_base(n, "0123456789");
	if (len < 1 && n != 0)
		return (-1);
	return (len);
}

int	ft_print_uint(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789"));
}

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
}

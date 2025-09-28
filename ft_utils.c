/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyavas <alyavas@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:29:06 by alyavas           #+#    #+#             */
/*   Updated: 2025/09/28 16:55:48 by alyavas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int				len;
	int				res;
	unsigned long	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		res = ft_putnbr_base(n / base_len, base);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (write(1, &base[n % base_len], 1) == -1)
		return (-1);
	return (len + 1);
}

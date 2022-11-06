/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:20:23 by ikhabour          #+#    #+#             */
/*   Updated: 2022/11/06 12:20:24 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		count++;
		i++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
		count += ft_putnbr(nb);
	}
	else if (nb < 10)
		count += ft_putchar(nb + '0');
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putnbr_hexa(unsigned long int nb, char format)
{
	int		count;
	char	*lower;
	char	*upper;

	count = 0;
	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (nb > 15)
	{
		count += ft_putnbr_hexa(nb / 16, format);
		count += ft_putnbr_hexa(nb % 16, format);
	}
	else if (nb <= 9)
		count += ft_putchar(nb + '0');
	else if (format == 'X')
		count += ft_putchar(upper[nb]);
	else if (format == 'x')
		count += ft_putchar(lower[nb]);
	return (count);
}

int	ft_put_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + '0');
	else if (nb > 9)
	{
		count += ft_put_unsigned(nb / 10);
		count += ft_put_unsigned(nb % 10);
	}
	return (count);
}

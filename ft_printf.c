/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:57:18 by ikhabour          #+#    #+#             */
/*   Updated: 2022/11/06 10:57:20 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	if (c == 'p')
	{
		count = ft_putstr("0x");
		count += ft_putnbr_hexa(va_arg(args, unsigned long int), 'x');
	}
	if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count = ft_put_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		count = ft_putnbr_hexa(va_arg(args, unsigned int), 'x');
	if (c == 'X')
		count = ft_putnbr_hexa(va_arg(args, unsigned int), 'X');
	if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
			count += format_check(ptr, s[++i]);
		else if (s[i] != '%' && s[i])
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}

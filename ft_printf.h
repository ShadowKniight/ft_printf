/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:57:51 by ikhabour          #+#    #+#             */
/*   Updated: 2022/11/06 10:57:52 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putchar(char c);
int	ft_printf(const char *s, ...);
int	ft_put_unsigned(unsigned int nb);
int	ft_putnbr_hexa(unsigned long int nb, char format);

#endif

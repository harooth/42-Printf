/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagevorg <hagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:17 by hagevorg          #+#    #+#             */
/*   Updated: 2022/04/25 17:52:22 by hagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checking_i(int cur, int next)
{
	if ((cur == '%' && next == 's')
		|| (cur == '%' && (next == 'd' || next == 'i'))
		|| (cur == '%' && next == 'u')
		|| (cur == '%' && next == '%')
		|| (cur == '%' && next == 'x')
		|| (cur == '%' && next == 'X')
		|| (cur == '%' && next == 'c')
		|| (cur == '%' && next == 'p'))
		return (1);
	return (0);
}

int	checking(int cur, int next, va_list ap)
{
	int	count;

	count = 0;
	if (cur == '%' && next == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (cur == '%' && next == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (cur == '%' && (next == 'd' || next == 'i'))
		count += ft_putnbr(va_arg(ap, int));
	else if (cur == '%' && next == 'u')
		count += ft_putnbr_uns(va_arg(ap, unsigned int));
	else if (cur == '%' && next == '%')
		count += ft_putchar('%');
	else if (cur == '%' && next == 'x')
		count += tohex(va_arg(ap, unsigned long long), "0123456789abcdef");
	else if (cur == '%' && next == 'X')
		count += tohex(va_arg(ap, unsigned long long), "0123456789ABCDEF");
	else if (cur == '%' && next == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long long));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	count;
	int	i;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	va_list (ap);
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		count += checking(s[i], s[i + 1], ap);
		if (checking_i(s[i], s[i + 1]))
			i += 2;
		else
		{
			count += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// 	ft_printf("%u", -1);
// }
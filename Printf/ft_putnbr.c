/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagevorg <hagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:31 by hagevorg          #+#    #+#             */
/*   Updated: 2022/04/25 15:14:35 by hagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	i;
	int		len;

	len = 0;
	i = n;
	if (i < 0)
	{
		i = (i * -1);
		len += ft_putchar ('-');
	}
	if (i > 9)
	{
		len += ft_putnbr (i / 10);
		len += ft_putchar ((i % 10) + '0');
	}
	else
		len += ft_putchar (i + '0');
	return (len);
}

// int main()
// {
//     int a = ft_putnbr(-26154);
//     printf("\n%d", a);
// }

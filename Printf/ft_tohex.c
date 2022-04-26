/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagevorg <hagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:46 by hagevorg          #+#    #+#             */
/*   Updated: 2022/04/25 15:14:50 by hagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len16(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	tohex(unsigned int n, char *alphabet)
{
	int		next;
	int		len;
	int		copylen;
	char	*str;

	if (n == 0)
		return (ft_putchar('0'));
	if (!n)
		return (0);
	len = ft_len16(n);
	copylen = len;
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	while (n)
	{
		next = n % 16;
		n /= 16;
		str[len] = alphabet[next];
		--len;
	}
	ft_putstr (str);
	free (str);
	return (copylen);
}

// int main()
// {
//     int a = toHex(18446744073709551615, "0123456789abcdef");
//     // printf("%d", a);
//     return(0);
// }

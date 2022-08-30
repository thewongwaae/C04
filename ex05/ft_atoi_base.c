/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:54:14 by hwong             #+#    #+#             */
/*   Updated: 2022/08/30 11:19:51 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	is_valid(char *base)
{
	int	base_len;
	int	a;
	int	b;

	a = 0;
	base_len = get_len(base);
	if ((base_len == 1) || (*base == '\0'))
		return (0);
	while (*base)
	{
		if (*base <= 32 || *base == 127 || *base == 43 || *base == 45)
			return (0);
		b = a + 1;
		while (b < get_len(base))
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	output;
	int	sign;

	output = 0;
	sign = 1;
	while (*str)
	{
		while (*str == ' ')
			str++;
		while ((*str == '+') || (*str == '-'))
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			output *= 10;
			output += *str - '0';
			str++;
		}
		return (output * sign);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	validity;
	int	nb;

	if (is_valid(base) == 1)
	{
		validity = is_valid(base);
		len = get_len(base);
		nb = ft_atoi(str);
		if (validity == 1)
		{
			if (nb < 0)
			{
				ft_putchar('-');
				nb *= -1;
			}
			if (nb < len)
				ft_putchar(base[nb]);
			if (nb >= len)
			{
				ft_putnbr_base(nb / len, base);
				ft_putnbr_base(nb % len, base);
			}
		}
	}
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi_base("	+++++--133742", "0123456789"));
	printf("%d\n", ft_atoi_base("	     ---101010", "01"));
	printf("%d\n", ft_atoi_base(" 	+---2a", "0123456789abcdef"));
}
*/
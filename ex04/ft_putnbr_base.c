/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 08:17:36 by hwong             #+#    #+#             */
/*   Updated: 2022/08/30 11:20:21 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

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
	while (base[a])
	{
		if (base[a] <= ' ' || base[a] == 127
			|| base[a] == '+' || base[a] == '-')
			return (0);
		b = a + 1;
		while (b < base_len)
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	validity;

	base_len = get_len(base);
	validity = is_valid(base);
	if (validity == 1)
	{
		if (nbr < 0)
		{
			print('-');
			nbr *= -1;
		}
		if (nbr < base_len)
			print(base[nbr]);
		if (nbr >= base_len)
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putnbr_base(nbr % base_len, base);
		}
	}
}

/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(1, "poneyvif");
	printf("\n");
	ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(53, "0123456789abcdef");
}
*/
/*
int	main(void)
{
	ft_putnbr_base(42, "0123456789");
	printf("\n");
	ft_putnbr_base(-2147482648, "poneyvif");
	printf("\n");
	ft_putnbr_base(10, "poneyvif");
	printf("\n");
	ft_putnbr_base(2, "01");
	printf("\n");
	ft_putnbr_base(2, "1");
	printf("\n");
	ft_putnbr_base(42, "");
	printf("\n");
	ft_putnbr_base(0, "\t01");
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:19:13 by hwong             #+#    #+#             */
/*   Updated: 2022/08/30 11:19:05 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		print('-');
		print('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		print('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		print(nb + 48);
		return ;
	}
	else
		ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

/*
basically itoa

int main (void)
{
	ft_putnbr(-2147483648);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:44:23 by hwong             #+#    #+#             */
/*   Updated: 2022/08/28 18:00:10 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

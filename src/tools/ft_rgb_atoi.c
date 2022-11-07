/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:03:08 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 15:41:50 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_invalid_chars(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len > 3)
		return (true);
	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == false)
			return (true);
		i++;
	}
	return (false);
}

int	ft_rgb_atoi(char *str)
{
	int		i;
	int		res;
	bool	str_invalid;

	str_invalid = check_invalid_chars(str);
	if (str_invalid == true)
		return (-1);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (res < 0 || res > 255)
		return (-1);
	else
		return (res);
}

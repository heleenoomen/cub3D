/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:41:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/24 18:25:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static int	config_player(t_data *data, int x, int y)
{

	if ((data->player->dir != VOID) || (x == 0 || y == 0))
	{
		data->parse_error = true;
		return (print_line_error(data, y));
	}
	data->player->x = x;
	data->player->y = y;
	data->player->dir = data->map[x][y];
	data->map[x][y] = ZERO;
	return (EXIT_SUCCESS);
}

static int	check_item_validity(t_data *data, char item, int y_pos)
{
	int i;

	i = 0;
	while (i < NUM_ITEMS)
	{
		if (data->conf->items[i] == item)
			return (EXIT_SUCCESS);
		i++;
	}
	data->parse_error = true;
	return (print_line_error(data, (y_pos)));
}

void	parse_player(t_data *data)
{
	char	item;
	int 	x;
	int 	y;

	y = 0;
	while (y < data->tab->max_y)
	{
		x = 0;
		while (x < data->tab->max_x)
		{
			item = data->map[x][y];
			if (check_item_validity(data, item, y) == EXIT_FAILURE)
				return ;
			if (item == 'N' || item == 'S' || item == 'E' || item == 'W')
				if (config_player(data, x, y) == EXIT_FAILURE)
					return ;
			x++;
		}
		y++;
	}
}

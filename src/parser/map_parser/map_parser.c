/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:59 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 17:39:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

/*
 * Parses the map after floor, ceiling and textures were parsed.
 * Transforms the map from fd to .cub file to the rectangular 2D array.
 * Fills all empty (undefined) slots with VOID elements.
 * After parsing - performs different checks on map elements.
 * If the map configuration is false, sets parse error flag to true.
 *
 * Example:
 * MAP FROM .cub FILE DESCRIPTOR:
		111111111111111111111111111111111        1111111111111111111111111
		1E0000001000000000110000000000001        1000000000110000000000001
		100000001011000001110000000000001        1011000001110000000000001
		100001111001000000000000000000001        1001000000000000000000001
		100011111011000001110000000000001111111111011000001110000000000001
		100000000000000000000000000000000000000000000000000000000000000001
		111101111111110111000000100011100001111111101110000001000101000101
		111101111111110111010100100011110111111111101110101001000101000101
		110000001101010111000000101011100010011010101110000001000101000101
		100000000000000011000000100000000000000000000110000001000101000101
		100000000000000011010100100011000000000000000110101001000101000101
		110000011101010111110111100011110000111110101111110111101111101111
		11110111 1110101 10111101000111100111 1110101 10111101000101000101
		11111111 1111111 11111111111111101111 1111111 11111111111111111111
		111101111111110111000000100011100001111111101110000001000101000101
		111101111111110111010100100011110111111111101110101001000101000101
		110000000000000000000000101011100010011010101110000001000101000101
		100000000000000011000000100011000000000000000110000001000101000101
		100000000000000011010100101011000000000000000110101001000101000101
		110000011101010111110111100011110000111110101111110111101111101111
		10110111 1110101 10111101000111100111 1110101 10111101000101001001
		11111111 1111111 11111111111111111111 1111111 11111111111111111111

  * CONVERTED RECTANGULAR MAP (all minus signs are VOID elements):
		111111111111111111111111111111111--------1111111111111111111111111
		100000001000000000110000000000001--------1000000000110000000000001
		100000001011000001110000000000001--------1011000001110000000000001
		100001111001000000000000000000001--------1001000000000000000000001
		100011111011000001110000000000001111111111011000001110000000000001
		100000000000000000000000000000000000000000000000000000000000000001
		111101111111110111000000100011100001111111101110000001000101000101
		111101111111110111010100100011110111111111101110101001000101000101
		110000001101010111000000101011100010011010101110000001000101000101
		100000000000000011000000100000000000000000000110000001000101000101
		100000000000000011010100100011000000000000000110101001000101000101
		110000011101010111110111100011110000111110101111110111101111101111
		11110111-1110101-10111101000111100111-1110101-10111101000101000101
		11111111-1111111-11111111111111101111-1111111-11111111111111111111
		111101111111110111000000100011100001111111101110000001000101000101
		111101111111110111010100100011110111111111101110101001000101000101
		110000000000000000000000101011100010011010101110000001000101000101
		100000000000000011000000100011000000000000000110000001000101000101
		100000000000000011010100101011000000000000000110101001000101000101
		110000011101010111110111100011110000111110101111110111101111101111
		10110111-1110101-10111101000111100111-1110101-10111101000101001001
		11111111-1111111-11111111111111111111-1111111-11111111111111111111
		------------------------------------------------------------------
 * */
void	parse_map(t_data *data)
{
	if (create_map(data) == EXIT_FAILURE)
		data->parse_error = true;
	if (data->parse_error == false)
	{
		parse_player(data);
		if (data->parse_error == false && data->player->dir == VOID)
		{
			data->parse_error = true;
			return (print_error(NO_PLAYER, NULL));
		}
	}
	if (data->parse_error == false)
		check_map_borders(data);
	if (data->parse_error == false)
		check_invalid_void_spaces(data);
	data->map_parsed = true;
}

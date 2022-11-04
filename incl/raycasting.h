/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/04 17:36:17 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/* rays_minimap.c */
void	cast_rays(t_data *data, double step);

/* render.c */
void	render(t_data *data);

/* dda_initializer.c */
void	init_dda(t_data *data, t_ray *ray, double camera_x);

#endif

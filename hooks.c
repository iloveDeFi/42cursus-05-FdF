/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:24:48 by bat               #+#    #+#             */
/*   Updated: 2023/09/07 14:49:43 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_shutdown(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free_map_parse(data);
	exit (0);
	return (0);
}

int	ft_keyboard(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_shutdown(data);
	else if (keycode == 0 || keycode == 123)
		data->key.horizontal -= MOVE;
	else if (keycode == 2 || keycode == 124)
		data->key.horizontal += MOVE;
	else if (keycode == 13 || keycode == 126)
		data->key.vertical -= MOVE;
	else if (keycode == 1 || keycode == 125)
		data->key.vertical += MOVE;
	else if (keycode == 32)
		data->key.altitude += ALTITUDE;
	else if (keycode == 37)
		data->key.altitude -= ALTITUDE;
	else if (keycode == 15)
		data->alpha += ROTATE;
	else if (keycode == 17)
		data->alpha -= ROTATE;
	else if (keycode == 6)
		data->size += ZOOM;
	else if (keycode == 7 && data->size > 5)
		data->size -= ZOOM;
	return (0);
}

int	ft_mouse(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == 4)
		data->size += ZOOM;
	else if (button == 5 && data->size > 5)
		data->size -= ZOOM;
	else if (button == 1)
		data->key.background += 1;
	else if (button == 2)
		data->key.background -= 1;
	return (0);
	}

void	ft_instructions(t_data *data)
{
	mlx_key_hook(data->win_ptr, ft_keyboard, data);
	mlx_mouse_hook(data->win_ptr, ft_mouse, data);
	mlx_hook(data->win_ptr, 17, 0, ft_shutdown, data);
}

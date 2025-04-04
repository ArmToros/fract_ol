/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:45:53 by armtoros          #+#    #+#             */
/*   Updated: 2025/04/04 17:53:10 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_key(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
    {
        close_window(data);
    }
    return (0);
}

int close_window(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}


void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	if (!data->win)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		exit(EXIT_FAILURE);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			*(int *)(data->addr + (y * data->line_len + x * (data->bpp / 8))) = 0x000000; // black
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, handle_key, data);
	mlx_hook(data->win, 17, 0L, close_window, data);
}

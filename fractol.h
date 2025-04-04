/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:30:50 by armtoros          #+#    #+#             */
/*   Updated: 2025/04/04 17:48:09 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 3840
# define HEIGHT 2160
# define ESC_KEY 65307


typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
} t_data;

void	init_window(t_data *data);
int		handle_key(int keycode, t_data *data);
int		close_window(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:10 by anvannin          #+#    #+#             */
/*   Updated: 2023/08/01 20:14:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_labels(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 15, HEX_WHITE,
		"'ESC': close window");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, HEX_WHITE,
		"Right click: right click");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 45, HEX_WHITE,
		"Left click: left click");
}

int	window_init(t_mlx *mlx, t_scene *scene)
{
	if (!mlx)
		return (0);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"MiniRT");
	if (!mlx->win_ptr)
		return (0);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!(mlx->img.img_ptr))
		return (0);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	render(mlx, scene);
	return (1);
	(void)scene;
}

void	my_pixel_put(t_img100 img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	window_destroy(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
}

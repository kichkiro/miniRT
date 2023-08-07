/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:29:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/08/07 18:55:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*!
* @brief
	Converts a t_rgb structure to an int.
*@param	rgb
	rgb structure.
*@return
	integer color.
*@note
	The colors are stored in separate integer variables inside the structure.
	We shift the bits of each color by the appropriate number of bits
	(red by 16, green by 8, and blue by 0),
	and then combine them using bitwise OR (|).
	The resulting integer color represents the RGB value.
*/
int	rgb_to_int(t_rgb *rgb)
{
	return ((rgb->red << 16) | (rgb->blue << 8) | rgb->green);
}

int	rgb_to_int2(int red, int green, int blue)
{
	return ((red << 16) | (blue << 8) | green);
}

/*!
	@brief	Print the RGB values of a t_rgb structure as integers.
	@param	rgb rgb structure.
*/
void	print_rgb_int(t_rgb *rgb)
{
	printf("%d\t%d\t%d\n", rgb->red, rgb->green, rgb->blue);
}

/*!
	@brief	Print the RGB values of a t_rgb structure as hexadecimal.
	@param	rgb rgb structure.
*/
void	print_rgb_hex(t_rgb *rgb)
{
	printf("0xFF%X\n", rgb_to_int(rgb));
}

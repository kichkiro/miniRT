/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_set_to_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:08:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/07 12:11:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	t_scene_set_to_head(t_scene **scene)
{
	while (scene && *scene && (*scene)->prev)
		*scene = (*scene)->prev;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:13 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/13 16:29:01 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


/*
** lorsqu'on opendir(), avant de renvoyer -1,
** verifier qu'il ne s'agit pas d'un fichier.
**  dans ce cas on l'affiche directement
*/
static int	store_requested_dir(char *dir_name, t_ls_args *ls_args)
{
	t_dir_info		*new_dir;
	DIR				*dirp;
	t_dir_info		*head;
//	t_file_infos	*infos;

	head = ls_args->dirs;
	new_dir = (t_dir_info *)malloc(sizeof(t_dir_info));
	new_dir->name = ft_strdup(dir_name);
	new_dir->next = NULL;
	if (!(ls_args->dirs))
		ls_args->dirs = new_dir;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_dir;
	}
	if (!(dirp = opendir(dir_name)))
		return (0);
	closedir(dirp);
	return (1);
}

void			check_arguments(int ac, char **av, t_ls_args *ls_args)
{
	int			i;
	char		*args_list;
	int			nb_of_dirs;

	i = 0;
	args_list = ft_strnew(2);
	nb_of_dirs = 0;
	while (++i < ac && av[i][0] == '-' && is_option(&av[i][1], ls_args))
	{
		args_list = ft_mem_realloc(args_list, ft_strlen(args_list) + ft_strlen(av[i]));
		args_list = ft_strcat(args_list, &av[i][1]);
	}
	while (i < ac)
	{
		nb_of_dirs++;
		if (!store_requested_dir(av[i], ls_args))
			print_error(av[i]);
		i++;
	}
	ls_args->options = ft_strdup(args_list);
	ft_memdel((void **)&args_list);
}

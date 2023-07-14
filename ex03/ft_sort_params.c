/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:40:27 by edi-iori          #+#    #+#             */
/*   Updated: 2023/07/13 12:38:46 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s2[i] - s1[i] != 0)
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_strings(char *argv[], int len)
{
	char	*temp;
	int		i;

	i = 1;
	while (i < len - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			temp = argv[i + 1];
			argv[i + 1] = argv[i];
			argv[i] = temp;
			ft_sort_strings(argv, len);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	ft_sort_strings(argv, argc);
	i = 1;
	while (i < argc)
	{	
		print(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}

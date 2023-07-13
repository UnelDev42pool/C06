/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:40:27 by edi-iori          #+#    #+#             */
/*   Updated: 2023/07/11 09:27:25 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

int	main(int argc, char *argv[])
{
	int i;
	int j;
	char temp[100];
	char str[100][100];

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			str[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc - 1){
		j = 0;
		while (j < argc - 1){
			if (ft_strcmp(str[i],str[j]) < 0){
				ft_strcpy(temp, str[i]);
				ft_strcpy(str[i], str[j]);
				ft_strcpy(str[j], temp);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{	
		print(str[i]);
		write(1,"\n", 1);
		i++;
	}
}
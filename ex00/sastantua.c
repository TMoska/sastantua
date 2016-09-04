/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:28:47 by tmoska            #+#    #+#             */
/*   Updated: 2016/09/04 13:37:46 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		base_ln_len(int size, int floor_num)
{
	int line_diff;
	int i;

	if (floor_num == size)
		return (1);
	line_diff = 4;
	i = floor_num;
	while (i <= size)
	{
		if ((floor_num % 2 == 0) && (i % 2 == 1))
			line_diff += 4;
		else if (floor_num % 2 == 0)
			line_diff += 2;
		else if ((floor_num % 2 == 1) && (i % 2 == 1))
			line_diff += 2;
		else
			line_diff += 4;
		i++;
	}
	return (base_ln_len(size, floor_num + 1) + line_diff);
}

void	build_line(int length, int offset)
{
	while (--offset >= 0)
		ft_putchar(' ');
	ft_putchar('/');
	while (--length >= 0)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	build_floor(int size, int floor_num)
{
	int levels;
	int offset;
	int length;
	int base_offset;

	levels = 3 + (size - floor_num);
	length = base_ln_len(size, floor_num);
	base_offset = ((base_ln_len(size, 1) - base_ln_len(size, floor_num)) / 2);
	while (levels > 0)
	{
		offset = base_offset + levels - 7 + ((floor_num + 5));
		if ((size != floor_num) && floor_num % 2 == 0)
			build_line(length, offset);
		else
			build_line(length, offset);
		levels--;
		length += 2;
	}
}

void	sastantua(int size)
{
	int floor_num;

	floor_num = size;
	while (floor_num > 0)
	{
		build_floor(size, floor_num);
		floor_num--;
	}
}

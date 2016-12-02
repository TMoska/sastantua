#include "sastantua.h"

int		main(int argc, char **argv)
{
  int floors;

	if (argc != 2 || !(floors = ft_atoi(argv[1])))
		return (0);
	sastantua(floors);
	return (0);
}

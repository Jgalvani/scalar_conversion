/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:45:03 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/10 18:45:05 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/scalar.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	
	Type	type;
	
	type.printLitteralType(av[1]);
	
	return 0;
}
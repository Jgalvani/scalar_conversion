/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:44:37 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/10 18:44:39 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HPP
# define TYPE_HPP

# include "scalar.hpp"

class	Type
{
	public:
	char			find(char *str);
	bool			isInt(char *str);
	unsigned int	charCounter(char *str, unsigned int *dot);
	
	void			printLitteralType(char *str);
	void			printChar(char *str);
	void			printInt(char *str);
	void			printFloat(char *str);
	void			printDouble(char *str);
	void			printError(char *str);
	void			printNan(char *str);
	void			printNanf(char *str);

	bool			overflow(char *str);

	Type();	
	Type(Type const & src);	
	~Type();	

	Type const &	operator=(Type const & rhs);
};

#endif

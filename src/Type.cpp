/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:44:56 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/10 18:44:58 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/scalar.hpp"

//Member functions
/***	Determine type	***/
unsigned int	Type::charCounter(char *str, unsigned int *dot)
{
	unsigned int	dotCounter = 0;
	unsigned int	charCounter = 0;

	for (int i = 0; str[i]; i++)
	{
		if (i == 0 and str[i] == '-')
			continue;
		if (str[i] == '.')
			dotCounter++;
		else if (std::isdigit(static_cast<unsigned char>(str[i])) == false)
			charCounter++;
	}
	*dot = dotCounter;
	return charCounter;
}	

bool	Type::isInt(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])) == false)
			return false;
	}
	return true;
}

char	Type::find(char *str)
{
	unsigned int	dots = 0;	
	unsigned int	chars = this->charCounter(str, &dots);

	if (this->isInt(str) == true)
		return 'i';
	else if (std::strlen(str) == 1)
		return 'c'; 
	else if ((chars > 1 or dots > 1 or (chars == 1 and (dots != 1 or str[std::strlen(str) - 1] != 'f'))) and strcmp(str, "nan") and strcmp(str, "nanf") and strcmp(str, "-inf") and strcmp(str, "+inf") and strcmp(str, "-inff") and strcmp(str, "+inff"))
		return 'e';
	else if (chars == 1 or strcmp(str, "-inff") == 0 or strcmp(str, "+inff") == 0)
		return 'f';
	else if (strcmp(str, "nan") == 0)
		return 'n';
	else if (strcmp(str, "nanf") == 0)
		return 'm';

	return 'd';
}

/***	Overflow	***/
bool	Type::overflow(char *str)
{
	long int l = atol(str);
	if (l > INT_MAX or l < INT_MIN or strcmp(str, "-inf") == 0 or strcmp(str, "+inf") == 0 or strcmp(str, "+inff") == 0 or strcmp(str, "-inff") == 0)
		return true;

	return false;
}

/***	Convert, Cast and Print	***/
void	Type::printChar(char *str)
{
	char c = *str;

	if (isprint(static_cast<int>(c)))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	Type::printInt(char *str)
{
	int i = atoi(str);

	if (isprint(i))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (this->overflow(str))
	{
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0"<< std::endl;
	}
}

void	Type::printFloat(char *str)
{
	float f = static_cast<float>(atof(str));

	if (isprint(static_cast<int>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (this->overflow(str))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		
	std::cout << "float: " << f << 'f' << std::endl;
	
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	Type::printDouble(char *str)
{
	double d = (atof(str));

	if (isprint(static_cast<int>(d)))
		std::cout << "char: " << static_cast<char>(d)<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (this->overflow(str))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;

	std::cout << "double: " << d << std::endl;
}

void	Type::printError(char *str)
{
	str = NULL;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	Type::printNan(char *str)
{
	double d = nan(str);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	Type::printNanf(char *str)
{
	float f = nanf(str);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	Type::printLitteralType(char *str)
{
	char	litteralType = this->find(str);
	char	litteralTypeTab[7] = {'c', 'i', 'f', 'd', 'e', 'n', 'm'};
	void	(Type::*printFunctions[7])(char *str) = {&Type::printChar, &Type::printInt, &Type::printFloat, &Type::printDouble, &Type::printError, &Type::printNan, &Type::printNanf};
	
	for (int i = 0; i < 7; i++)
	{
		if (litteralType == litteralTypeTab[i])
			(this->*printFunctions[i])(str);
	}
}

//Constructors
Type::Type(){}

Type::Type(Type const & src)
{
	*this = src;
}

//Destructor
Type::~Type(){}

//Operator overload
Type const &	Type::operator=(Type const & rhs)
{
	if (this != &rhs)
		return rhs;
	return *this;
}

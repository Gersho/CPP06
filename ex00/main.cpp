/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:28:40 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/19 16:55:58 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cctype>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (-1);
	}
	double	input;
	if (std::isalpha(av[1][0]) && !av[1][1])
		input = static_cast<char>(av[1][0]);
	else
		input = std::atof(av[1]);

//need handle impossible AND non printable differently
	std::cout << "char: ";
	if (std::isprint(static_cast<char>(input)))
		std::cout << static_cast<char>(input) << std::endl;
	else
		std::cout << "impossible." << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

/*

Write a program that takes a string representation of a C++ literal value (in its most
common form) as a parameter. This literal must belong to one of the following a scalar
types: char, int, float or double. Only the decimal notation will be used.

Examples of char literal values: ’c’, ’a’... To simplify, please note that: non displayable characters can’t be passed as a parameter to your program, and if a conversion
to char is not displayable, output a notification instead.

Examples of int literal values: 0, -42, 42...

Examples of float literal values: 0.0f, -4.2f, 4.2f... You will also accept these
pseudo literals as well, you know, for science: -inff, +inff and nanf.

Examples of double literal values: 0.0, -4.2, 4.2... You will also accept these pseudo
literals as well, you know, for fun: -inf, +inf and nan.

Your program must detect the literal’s type, acquire that literal in the right type (so
it’s not a string anymore), then convert it explicitly to each of the three other types and
display the results using the same formatting as below.

If a conversion does not make
sense or overflows, display that the conversion is impossible. You can include any header
you need to handle numeric limits and special values.


./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0


 */


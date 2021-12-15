/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:19:02 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/15 15:43:52 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>

class Base { public: virtual ~Base(){}; };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
	Base *ptr;

	srand(std::time(NULL));
	int num = rand() % 3;
	switch (num)
	{
		case 0:
			ptr = new A;
			std::cout << "Building A" << std::endl;
			break;
		case 1:
			ptr = new B;
			std::cout << "Building B" << std::endl;
			break;
		case 2:
			ptr = new C;
			std::cout << "Building C" << std::endl;
			break;
		default:
			return NULL;
	}
	return ptr;
}

void identify(Base* p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "A" << std::endl;
	if (b)
		std::cout << "B" << std::endl;
	if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	int i = -1;

	while (i < 3)
	{
		i++;
		if (i == 0)
		{
			try
			{
				A &a  = dynamic_cast<A&>(p);
				(void) a;
				std::cout << "A" << std::endl;
				break;
			}
			catch (std::exception &e)
			{
				continue;
			}
		}
		
		if (i == 1)
		{
			try
			{
				B &b  = dynamic_cast<B&>(p);
				(void) b;
				std::cout << "B" << std::endl;
				break;
			}
			catch (std::exception &e)
			{
				continue;
			}
		}

		if (i == 2)
		{
			try
			{
				C &c  = dynamic_cast<C&>(p);
				(void) c;
				std::cout << "C" << std::endl;
				break;
			}
			catch (std::exception &e)
			{
				continue;
			}
		}
	}
}

void	testrandom()
{
	int i = 0;
	int a,b,c;
	
	a = b = c = 0;
	srand(std::time(NULL));
	while (i < 10000)
	{
		int num = rand() % 3;
		if (num == 0)
			a++;
		if (num == 1)
			b++;
		if (num == 2)
			c++;
		i++;
	}
	std::cout << "Testing random:" << std::endl;
	std::cout << "(0):" << a << std::endl;
	std::cout << "(1):" << b << std::endl;
	std::cout << "(2):" << c << std::endl;
}

int	main(void)
{
	testrandom();
	
	Base *mysterious_ptr = generate();
	if (!mysterious_ptr)
		return (-1);
	Base &mysterious_ref = *mysterious_ptr;

	std::cout << "Calling: void identify(Base* p)" << std::endl;
	identify(mysterious_ptr);
	std::cout << "Calling: void identify(Base& p)" << std::endl;
	identify(mysterious_ref);
}


/*

Create a class Base that only possesses a public virtual destructor. 
Create three
empty classes A, B and C that publicly inherit from Base.
Write a function "Base * generate(void);" that randomly instanciates A, B or C
and returns the instance as a Base pointer. Feel free to use anything you like for the
randomness.
Write a function "void identify(Base* p);" that displays "A", "B" or "C" according to the real type of p.
Write a function "void identify(Base& p);" You should never use a pointer inside
this function. that displays "A", "B" or "C" according to the real type of p.
Wrap these functions in a program that proves that everything works as intended.
<typeinfo> is forbidden.


*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:47:16 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/15 16:10:39 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

class Data
{
	public:

	int		num;
};


uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main(void)
{
	Data		*data = new Data;
	data->num = 42;
	uintptr_t	serial = serialize(data);
	Data		*deserial = deserialize(serial);

	std::cout << "data ptr: " << data << std::endl;
	std::cout << "data.num: " << data->num << std::endl;
	std::cout << "deserial: " << deserial << std::endl;
	std::cout << "deserial.num " << deserial->num << std::endl;

	delete(data);
}

/* 


Write a function "uintptr_t serialize(Data* ptr);". This function will return
the parameter in an integer type.

Write a function "Data* deserialize(uintptr_t raw);". This function will return
the raw data you created using "serialize" to a Data structure.

Wrap these two functions in a program that proves that everything works as intended.
You must create a valid data structure.
Take a Data address use serialize on it.
Send the return value in deserialize.
Check if the return value is equal to the first pointer.
Do not forget to include the Data structure you used.

*/
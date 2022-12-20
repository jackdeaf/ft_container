/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:51:20 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/20 18:55:36 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"
#include "vector.hpp"
#include <sstream>

using std::string;

template <typename A>
void	pstd(std::vector<A> p)
{
	for (typename std::vector<A>::size_type i = 0; i < p.size(); ++i)
		cout << p[i] << " ";
	cout << endl;
	cout << "std size: " << p.size() << " | " << "std capacity: " << p.capacity() << endl;
}

template <typename A>
void	pft(ft::vector<A> p)
{
	for (typename ft::vector<A>::size_type i = 0; i < p.size(); ++i)
		cout << p[i] << " ";
	cout << endl;
	cout << "ft size: " << p.size() << " | " << "ft capacity: " << p.capacity() << endl;
	cout << endl;
}

template<class T, class Alloc>
void	cmp(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs)
{
	cout << "xxxSTDxxx" << endl;
	cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << endl;
	cout << "lt: " << (lhs < rhs) << " | le: " << (lhs <= rhs) << endl;
	cout << "gt: " << (lhs > rhs) << " | ge: " << (lhs >= rhs) << endl;
	cout << endl;
}

template<class T, class Alloc>
void	cmp(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{
	cout << "xxxFTxxx" << endl;
	cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << endl;
	cout << "lt: " << (lhs < rhs) << " | le: " << (lhs <= rhs) << endl;
	cout << "gt: " << (lhs > rhs) << " | ge: " << (lhs >= rhs) << endl;
}

void	ft_test(void)
{
	const std::size_t max_size = std::vector<int>().max_size();
	std::vector<int> v(max_size + 1);
}

int main()
{
	ft_test();
	system("leaks main");
	return (0);
}

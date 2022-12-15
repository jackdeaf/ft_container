/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:51:20 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/15 18:15:23 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT
#include "lib.hpp"
#include "vector.hpp"
#include "doctest.hpp"

int	doc(int *ac, char **av)
{
	doctest::Context context;
	context.addFilter("test-case-exclude", "*math*");
	context.setOption("abort-after", 5);
	context.setOption("order-by", "name");
	context.applyCommandLine(*ac, av);
	context.setOption("no-breaks", true);
	int res = context.run();
	if (context.shouldExit())
		return res;
	int client_stuff_return_code = 0;
	return (res + client_stuff_return_code);
}


void	ft_test(void)
{}

TEST_CASE("Iterator & const iterator")
{
	std::vector<int> vstd;
	ft::vector<int> vft;

	for (int i = 1; i <= 7; ++i)
	{
		vstd.push_back(i);
		vft.push_back(i);
	}
	typedef std::vector<int>::iterator stditer;
	typedef ft::vector<int>::iterator ftiter;
	typedef std::vector<int>::const_iterator cstditer;
	typedef ft::vector<int>::const_iterator cftiter;

	// iterator & const iterator parameter constructor
	stditer sit = vstd.begin();
	stditer site = vstd.end();
	ftiter fit = vft.begin();
	ftiter fite = vft.end();

	cstditer csit = vstd.begin();
	cstditer csite = vstd.end();
	cftiter cfit = vft.begin();
	cftiter cfite = vft.end();

	// iterator & const iterator default constructor
	stditer dit, dite;
	ftiter dfit, dfite;

	cstditer cdit, cdite;
	cftiter cdfit, cdfite;
	
	// iterator & const iterator assign constructor
	dit = sit; dite = site;
	dfit = fit; dfite = fite;

	cdit = csit; cdite = csite;
	cdfit = cfit; cdfite = cfite;

	// iterator & const iterator copy constructor
	stditer stdc(dit);
	stditer stdce(dite);
	ftiter ftc(dfit);
	ftiter ftce(dfite);

	cstditer cstdc(cdit);
	cstditer cstdce(cdite);
	cftiter cftc(cdfit);
	cftiter cftce(cdfite);

	SUBCASE("iterator & const iterator[] operator")
	{
		CHECK(stdc[0] == ftc[0]);
		CHECK(stdc[1] == ftc[1]);
		CHECK(stdc[2] == ftc[2]);
	
		CHECK(cstdc[0] == cftc[0]);
		CHECK(cstdc[1] == cftc[1]);
		CHECK(cstdc[2] == cftc[2]);
	}

	SUBCASE("iterator & const iterator bool")
	{
		CHECK((ftc == dfit) == (stdc == dit));
		CHECK((ftc != dfit) == (stdc != dit));
		CHECK((ftc == dfite) == (stdc == dite));
		CHECK((ftc > dfite) == (stdc > dite));
		CHECK((ftc < dfite) == (stdc < dite));
		CHECK((ftc < dfite) == (stdc < dite));
		CHECK((ftc > dfite) == (stdc > dite));
		CHECK((ftc >= dfite) == (stdc >= dite));
		CHECK((ftc <= dfite) == (stdc <= dite));
		CHECK((ftc <= dfite) == (stdc <= dite));
		CHECK((ftc >= dfite) == (stdc >= dite));
		
		CHECK((cftc == cdfit) == (cstdc == cdit));
		CHECK((cftc != cdfit) == (cstdc != cdit));
		CHECK((cftc == cdfite) == (cstdc == cdite));
		CHECK((cftc != cdfite) == (cstdc != cdite));
		CHECK((cftc > cdfite) == (cstdc > cdite));
		CHECK((cftc < cdfite) == (cstdc < cdite));
		CHECK((cftc < cdfite) == (cstdc < cdite));
		CHECK((cftc > cdfite) == (cstdc > cdite));
		CHECK((cftc >= cdfite) == (cstdc >= cdite));
		CHECK((cftc <= cdfite) == (cstdc <= cdite));
		CHECK((cftc <= cdfite) == (cstdc <= cdite));
		CHECK((cftc >= cdfite) == (cstdc >= cdite));
	}

	SUBCASE("iterator & const iterator *operator, ++operator")
	{
		while (stdc != stdce && ftc != ftce)
			CHECK(*++stdc == *++ftc);
		while (cstdc != cstdce && cftc != cftce)
			CHECK(*++cstdc == *++cftc);
	}

	SUBCASE("iterator & const iterator *opeator, --operator")
	{
		while (stdc != vstd.begin() && ftc != vft.begin())
			CHECK(*--stdc == *--ftc);
		while (cstdc != vstd.begin() && cftc != vft.begin())
			CHECK(*--cstdc == *--cftc);
	}

	SUBCASE("iterator & const iterator *operator, operator++")
	{
		while (stdc != stdce && ftc != ftce)
			CHECK(*stdc++ == *ftc++);
		while (cstdc != cstdce && cftc != cftce)
			CHECK(*cstdc++ == *cftc++);
	}

	SUBCASE("iterator & const iterator *operator, operator--")
	{
		while (stdc != vstd.begin() && ftc != vft.begin())
			CHECK(*stdc-- == *ftc--);
		while (cstdc != vstd.begin() && cftc != vft.begin())
			CHECK(*cstdc-- == *cftc--);
	}

	SUBCASE("iterator & const iterator *operator, operator+=")
	{
		while (stdc != stdce && ftc != ftce)
		{
			stdc += 1; ftc += 1;
			CHECK(*stdc == *ftc);
		}
		while (cstdc != cstdce && cftc != cftce)
		{
			cstdc += 1; cftc += 1;
			CHECK(*cstdc == *cftc);
		}
	}

	SUBCASE("iterator & const iterator *operator, operator-=")
	{
		while (stdc != vstd.begin() && ftc != vft.begin())
		{
			stdc -= 1; ftc -= 1;
			CHECK(*stdc == *ftc);
		}
		while (cstdc != vstd.begin() && cftc != vft.begin())
		{
			cstdc -= 1; cftc -= 1;
			CHECK(*cstdc == *cftc);
		}
	}
	SUBCASE("iterator & const iterator operator-, operator+")
	{
		stditer stdplus = stdc + 2;
		ftiter ftplus = ftc + 2;
		CHECK(*stdplus == *ftplus);
		stdc += 3;
		ftc += 3;
		stditer stdm = stdc - 2;
		ftiter ftm = ftc - 2;
		CHECK(*stdm == *ftm);

		cstditer cstdplus = cstdc + 2;
		cftiter cftplus = cftc + 2;
		CHECK(*cstdplus == *cftplus);
		cstdc += 3;
		cftc += 3;
		cstditer cstdm = cstdc - 2;
		cftiter cftm = cftc - 2;
		CHECK(*cstdm == *cftm);

		// friend X operator+(size_t n, const X & other)
		stditer stdtry = 2 + stdc;
		ftiter fttry = 2 + ftc;
		CHECK(*stdtry == *fttry);
		
		cstditer cstdtry = 2 + cstdc;
		cftiter cfttry = 2 + cftc;
		CHECK(*cstdtry == *cfttry);

		CHECK((stdtry - stdc) == (fttry - ftc));
		CHECK((cstdtry - cstdc) == (cfttry - cftc));
	}
}

TEST_CASE("Reverse iterator & Const Reverse terator")
{
	ft::vector<int> ftv;
	std::vector<int> stdv;

	for (int i = 1; i <= 7; ++i)
	{
		ftv.push_back(i);
		stdv.push_back(i);
	}

	typedef std::vector<int>::reverse_iterator stditrev;
	typedef ft::vector<int>::reverse_iterator ftitrev;

	typedef std::vector<int>::const_reverse_iterator cstditrev;
	typedef ft::vector<int>::const_reverse_iterator cftitrev;

	// explicit constructor copy of iterator
	// stditrev stdb = stdv.end() cannot compile so
	// ftitrev ftb = ftv.end() should be fail compile
	stditrev stdb(stdv.end());
	stditrev stde(stdv.begin());
	ftitrev ftb(ftv.end());
	ftitrev fte(ftv.begin());

	cstditrev cstdb(stdv.end());
	cstditrev cstde(stdv.begin());
	cftitrev cftb(ftv.end());
	cftitrev cfte(ftv.begin());

	// default constructor
	stditrev sb;
	stditrev se;
	ftitrev fb;
	ftitrev fe;

	cstditrev csb;
	cstditrev cse;
	cftitrev cfb;
	cftitrev cfe;
	
	// assign copy constructor
	sb = stdb;
	se = stde;
	fb = ftb;
	fe = fte;

	csb = cstdb;
	cse = cstde;
	cfb = cftb;
	cfe = cfte;
	
	// copy constructor (both is same type class)
	stditrev s1(sb);
	stditrev s2(se);
	ftitrev f1(fb);
	ftitrev f2(fe);

	cstditrev cs1(csb);
	cstditrev cs2(cse);
	cftitrev cf1(cfb);
	cftitrev cf2(cfe);

	SUBCASE("base")
	{
		CHECK(*(s1.base()) == *(f1.base()));
		CHECK(*(s2.base()) == *(f2.base()));
		
		CHECK(*(cs1.base()) == *(cf1.base()));
		CHECK(*(cs2.base()) == *(cf2.base()));
	}

	SUBCASE("*operator")
	{
		while (s1 != s2 && f1 != f2)
			CHECK(*s1++ == *f1++);
		while (cs1 != cs2 && cf1 != cf2)
			CHECK(*cs1++ == *cf1++);
	}

	SUBCASE("++ --")
	{
		CHECK(*(s1 + 4) == *(f1 + 4));
		s1++;
		f1++;
		CHECK(*s1 == *f1);
		CHECK(*++s1 == *++f1);
		s1 += 3;
		f1 += 3;
		CHECK(*s1 == *f1);
		
		CHECK(*(cs1 + 4) == *(cf1 + 4));
		cs1++;
		cf1++;
		CHECK(*cs1 == *cf1);
		CHECK(*++cs1 == *++cf1);
		cs1 += 3;
		cf1 += 3;
		CHECK(*cs1 == *cf1);

		CHECK(*(s1 - 4) == *(f1 - 4));
		s1--;
		f1--;
		CHECK(*s1 == *f1);
		CHECK(*--s1 == *--f1);
		s1 -= 3;
		f1 -= 3;
		CHECK(*s1 == *f1);
		
		CHECK(*(cs1 - 4) == *(cf1 - 4));
		cs1--;
		cf1--;
		CHECK(*cs1 == *cf1);
		CHECK(*--cs1 == *--cf1);
		s1 -= 3;
		f1 -= 3;
		CHECK(*cs1 == *cf1);
	}
	SUBCASE("pointer and []")
	{
		int i = 0;
		for (; i < 7; ++i)
			CHECK(s1[i] == f1[i]);

		i = 0;
		for (; i < 7; ++i)
			CHECK(cs1[i] == cf1[i]);
	}
	SUBCASE("Relation Operations")
	{
		CHECK((*s1 == *cs1) == (*f1 == *cf1));	
		CHECK((*cs1 == *s2) == (*cf1 == *f2));	
		
		CHECK((*s1 != *cs1) == (*f1 != *cf1));	
		CHECK((*cs1 != *s2) == (*cf1 != *f2));	
		
		CHECK((*s1 < *cs1) == (*f1 < *cf1));	
		CHECK((*cs1 < *s2) == (*cf1 < *f2));	
		
		CHECK((*s1 > *cs1) == (*f1 > *cf1));	
		CHECK((*cs1 > *s2) == (*cf1 > *f2));	
		
		CHECK((*s1 <= *cs1) == (*f1 <= *cf1));	
		CHECK((*cs1 <= *s2) == (*cf1 <= *f2));	
		
		CHECK((*s1 >= *cs1) == (*f1 >= *cf1));	
		CHECK((*cs1 >= *s2) == (*cf1 >= *f2));	
	}
	SUBCASE("[non-member]operator+ , operator-")
	{
		CHECK(*(3 + s1) == *(3 + f1));
		CHECK(*(3 + cs1) == *(3 + cf1));

		CHECK((s2 - s1) == (f2 - f1));
		CHECK((s1 - cs2) == (f1 - cf2));
		
		CHECK((cs2 - cs1) == (cf2 - cf1));
		CHECK((cs1 - cs2) == (cf1 - cf2));
	}
}

TEST_CASE("vector construct")
{
	typedef std::vector<int> stv;
	typedef ft::vector<int> ftv;
	typedef stv::iterator	stviter;
	typedef ftv::iterator	ftviter;

	SUBCASE("Default Constructor")
	{
		stv slol;
		ftv flol;

		CHECK(slol.size() == flol.size());
		CHECK(slol.capacity() == flol.capacity());
	}

	SUBCASE("Constructor parameter")
	{
		stv slol(5);
		ftv flol(5);
		CHECK(slol.size() == flol.size());
		CHECK(slol.capacity() == flol.capacity());
		for (int i = 0; i < 5; ++i)
			CHECK(slol[i] == flol[i]);
		stv sp(5, 3);
		ftv fp(5, 3);
		CHECK(slol.size() == flol.size());
		CHECK(slol.capacity() == flol.capacity());
		for (int i = 0; i < 5; ++i)
			CHECK(slol[i] == flol[i]);
	}

	SUBCASE("Constructor with iterator parameter")
	{
		stv stmp(7); // init constructor with 7 size
		ftv ftmp(7);

		for (int i = 0; i < 7; ++i)
		{
			stmp.push_back(i + 1);
			ftmp.push_back(i + 1);
		}
		stviter sit = stmp.begin();
		stviter site = stmp.end();

		ftviter fit = ftmp.begin();
		ftviter fite = ftmp.end();
		for (int i = 0; i < 7; ++i)
		{
			*sit++ = i * i;
			*fit++ = i * i;
		}
		sit = stmp.begin();
		fit = ftmp.begin();

		stv sinter(sit + 5, site); // new constructor with deep copy
		ftv finter(fit + 5, fite);
//		stv sinter(site + 5, sit); // throw error when first is exceed the last
//		ftv finter(fite + 5, fit); // should be throw error
		CHECK(sinter.size() == finter.size());
		CHECK(sinter.capacity() == finter.capacity());
		sit = sinter.begin();
		site = sinter.end();
		fit = finter.begin();
		fite = finter.end();

		while (fit != fite && sit != site)
			CHECK(*fit++ == *sit++);
	}
	SUBCASE("vector copy constructor")
	{
		stv snew(7,7);
		ftv fnew(7,7);

		stv scopy1 = snew;
		ftv fcopy1 = fnew;
		CHECK(fcopy1.size() == scopy1.size());
		CHECK(fcopy1.size() == snew.size());

		stv scopy2(scopy1);
		ftv fcopy2(fcopy1);
		
		stviter sit = scopy2.begin();
		stviter site = scopy2.end();
		ftviter fit = fcopy2.begin();
		ftviter fite = fcopy2.end();
		
		CHECK(fcopy2.size() == scopy1.size());
		CHECK(fcopy2.size() == scopy2.size());
		CHECK(fcopy2.capacity() == scopy1.capacity());
		CHECK(fcopy2.capacity() == scopy2.capacity());

		while (sit != site && fit != fite)
			CHECK(*sit++ == *fit++);
	}
	SUBCASE("vector copy assign constructor")
	{
		stv snew(7,7);
		ftv fnew(7,7);

		stv sassign;
		ftv fassign;

		sassign = snew;
		fassign = fnew;
		CHECK(sassign.size() == fassign.size());
		CHECK(sassign.capacity() == fassign.capacity());
		
		stviter sit = sassign.begin();
		stviter site = sassign.end();

		ftviter fit = fassign.begin();
		ftviter fite = fassign.end();
		while (fit != fite && sit != site)
			CHECK(*fit++ == *sit++);
	}
}

TEST_CASE("Modifiers")
{
	typedef std::vector<int>	stdv;
	typedef ft::vector<int>		ftv;

	typedef stdv::iterator	siter;
	typedef ftv::iterator	fiter;

	SUBCASE("Assign")
	{
		stdv first;
		stdv second;
		stdv third;

		ftv f1;
		ftv f2;
		ftv f3;

		first.assign(7, 100);
		f1.assign(7, 100);

		siter it = first.begin() + 1;
		fiter fit = f1.begin() + 1;

		second.assign(it, first.end() - 1);
		f2.assign(fit, f1.end() - 1);

		int myints[] = {1776, 7, 4};
		third.assign(myints, myints + 3);
		f3.assign(myints, myints + 3);

		CHECK(first.size() == f1.size());
		CHECK(second.size() == f2.size());
		CHECK(third.size() == f3.size());

		CHECK(first.capacity() == f1.capacity());
		CHECK(second.capacity() == f2.capacity());
		CHECK(third.capacity() == f3.capacity());
		
		siter test = third.begin();
		siter teste = third.end();

		fiter ftest = f3.begin();
		fiter fteste = f3.end();
		while (test != teste && ftest != fteste)
			CHECK(*test++ == *ftest++);

		third.assign(first.begin(), first.end());
		f3.assign(f1.begin(), f1.end());
	
		test = third.begin();
		teste = third.end();
		ftest = f3.begin();
		fteste = f3.end();
		while (test != teste && ftest != fteste)
			CHECK(*test++ == *ftest++);

		third.assign(myints, myints + 3);
		f3.assign(myints, myints + 3);
		test = third.begin();
		teste = third.end();
		ftest = f3.begin();
		fteste = f3.end();
		while (test != teste && ftest != fteste)
			CHECK(*test++ == *ftest++);
		
	
		third.assign(second.begin(), second.end());
		f3.assign(f2.begin(), f2.end());
		test = third.begin();
		teste = third.end();
		ftest = f3.begin();
		fteste = f3.end();
		while (test != teste && ftest != fteste)
			CHECK(*test++ == *ftest++);
		
		CHECK(first.size() == f1.size());
		CHECK(second.size() == f2.size());
		CHECK(third.size() == f3.size());

		CHECK(first.capacity() == f1.capacity());
		CHECK(second.capacity() == f2.capacity());
		CHECK(third.capacity() == f3.capacity());
	}
}

int main(int argc, char **argv)
{
	ft_test();
#ifdef noasan
	system("leaks main");
#endif
	return (doc(&argc, argv));
}

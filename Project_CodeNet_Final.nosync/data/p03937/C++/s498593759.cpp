/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/25 09:33:21 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

/* #include <boost/multi_array.hpp> */
/* #include <boost/optional.hpp> */
/* #include <boost/range/irange.hpp> */
/* #include <boost/range/algorithm.hpp> */
/* #include <boost/range/adaptors.hpp> */
/* #include <boost/multiprecision/cpp_int.hpp> */
/* #include <boost/algorithm/string/classification.hpp> // is_any_of */
/* #include <boost/algorithm/string/split.hpp> */
/* #include <boost/algorithm/string/join.hpp> */
/* #include <boost/algorithm/string/replace.hpp> */
/* #include <boost/math/tools/minima.hpp> */
/* namespace adaptor = boost::adaptors; */
/* using boost::math::tools::brent_find_minima; */
/* using boost::irange; */
/* using boost::algorithm::join; */
/* using boost::algorithm::split; */
/* using boost::algorithm::replace_all; */
/* using boost::multiprecision::cpp_int; */

#define MOD 1e9+7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	int	h, w;
	cin >> h >> w;

	vector<string> V(h + 2);
	rep(i, h)
	{
		V.at(i + 1) = ".";
		string	s;
		cin >> s;
		V.at(i + 1) += s;
		V.at(i + 1) += ".";
	}
	rep(i, w + 2)
		V.at(0) += ".";
	V.at(h + 1) = V.at(0);
	int	y, x;
	y = h;
	x = w;
	while (!(x == 1 && y == 1))
	{
		if (V.at(y + 1).at(x - 1) == '#' || V.at(y - 1).at(x + 1) == '#' || (V.at(y - 1).at(x) == '#' && V.at(y).at(x - 1) == '#'))
		{
			cout << "Impossible" << endl;
			return ;
		}
		if (V.at(y - 1).at(x) == '#')
			y--;
		else if (V.at(y).at(x - 1) == '#')
			x--;
	}
	cout << "Possible" << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}

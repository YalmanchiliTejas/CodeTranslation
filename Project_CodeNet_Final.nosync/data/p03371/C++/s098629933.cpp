#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;

int64_t A, B, C, X, Y;

void solve()
{
	std::cin >> A >> B >> C >> X >> Y;

	int64_t ans1 = A * X + B * Y;
	int64_t ans2;
	if (X < Y)
	{
		ans2 = C * X * 2 + B * (Y - X);
	}
	else
	{
		ans2 = C * Y * 2 + A * (X - Y);
	}
	int64_t ans3 = C * std::max(X, Y) * 2;

	int64_t ans = std::min(ans1, std::min(ans2, ans3));
	std::cout << ans << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}

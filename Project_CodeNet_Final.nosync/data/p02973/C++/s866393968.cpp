#include <bits/stdc++.h>

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

void solve(void)
{
	ui N{};	std::cin >> N;

	typedef std::vector<ull> mVector;
	mVector vc(N, 0);
	for (ui i = 0; i < N; ++i) std::cin >> vc[i];

	std::reverse(vc.begin(), vc.end());

	mVector ret;
	ret.reserve(N);
	for (auto value : vc)
	{
		auto it = std::upper_bound(ret.begin(), ret.end(), value);

		if (it == ret.end())
			ret.push_back(value);
		else
			*it = value;
	}

	std::cout << ret.size() << "\n";

	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}

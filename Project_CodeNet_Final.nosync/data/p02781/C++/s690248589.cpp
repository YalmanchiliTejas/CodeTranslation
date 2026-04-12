#include <bits/stdc++.h>

using vi = std::vector<int64_t>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;

int K;
std::vector<int> N;
vvvi dp;

int64_t rc(int, int, bool);

int main()
{
	std::string n_str;
	std::cin >> n_str >> K;
	N.resize(n_str.size());
	for (int i{}; i < (int)n_str.size(); i++)
		N[i] = n_str[i] - '0';
	dp.resize(K, vvi(N.size(), vi(2, -1)));
	printf("%lld\n", rc(0, 0, false));

	return 0;
}

int64_t rc(int num_i, int N_i, bool free)
{
	if (num_i == K) return 1;
	if (N_i == N.size()) return 0;
	auto& ret{dp[num_i][N_i][free]};
	if (ret >= 0) return ret;
	ret = 0;
	for (int i{N_i}; i < N.size(); i++)
	{
		if (free)
			ret += 9 * rc(num_i + 1, i + 1, true);
		else
		{
			ret += std::max(0, N[i] - 1) * rc(num_i + 1, i + 1, true);
			if (N[i] != 0) ret += rc(num_i + 1, i + 1, false);
		}
		if (N[i] != 0) free = true;
	}
	
	return ret;
}
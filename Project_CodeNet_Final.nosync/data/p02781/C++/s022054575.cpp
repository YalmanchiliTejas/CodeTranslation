#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> make_vector(size_t sz)
{
	return vector<T>(sz);
}

template <typename T, typename... U>
auto make_vector(size_t sz, U... tails)
{
	return vector<decltype(make_vector<T>(tails...))>(sz, make_vector<T>(tails...));
}

template <typename T>
void fill_vector(vector<T> &v, T init)
{
	fill(v.begin(), v.end(), init);
}

template <typename T, typename U>
void fill_vector(vector<U> &vec, T init)
{
	for (auto &&v : vec)
	{
		fill_vector<T>(v, init);
	}
}

int main()
{
	string s;
	int64_t k;
	cin >> s >> k;

	int64_t n = s.size();

	auto dp = make_vector<int64_t>(n + 1, 2, 4);
	fill_vector<int64_t>(dp, 0);

	dp[0][1][0] = 1;

	for (int64_t i = 0; i < n; i++)
	{
		for (int64_t j = 0; j < 2; j++)
		{
			for (int64_t l = 0; l <= 3; l++)
			{
				int64_t lim = j ? (s[i] - '0') : 9;
				for (int64_t d = 0; d <= lim; d++)
				{
					if (l + (d != 0) <= 3)
					{
						dp[i + 1][j && (d == lim)][l + (d != 0)] += dp[i][j][l];
					}
				}
			}
		}
	}

	cout << (dp[n][0][k] + dp[n][1][k]) << endl;

	return 0;
}
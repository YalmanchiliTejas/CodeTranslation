#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

char field[110][110];

int main(int argc, char **argv)
{
	ll H, W; cin >> H >> W;
	for (ll i = 0; i < H; ++i)
		for (ll j = 0;j < W; ++j)
			cin >> field[i][j];

	vector<bool> col(W, false), row(H, false);

	for (ll h = 0; h < H; ++h)
		for (ll w = 0; w < W; ++w)
			if (field[h][w] == '#')
				col[w] = true;

	for (ll w = 0; w < W; ++w)
		for (ll h = 0; h < H; ++h)
			if (field[h][w] == '#')
				row[h] = true;

	for (ll h = 0; h < H; ++h)
	{
		if (!row[h]) continue;
		for (ll w = 0; w < W; ++w)
		{
			if (!col[w]) continue;
			std::cout << field[h][w];
		}
		std::cout << std::endl;
	}
}

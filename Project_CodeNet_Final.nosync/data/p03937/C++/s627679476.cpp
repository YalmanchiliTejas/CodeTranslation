#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

char field[10][10];
ll dx[2]{1, 0};
ll dy[2]{0, 1};
ll H, W;
bool ok{false};

void bfs(ll h, ll w)
{
	for (ll i = 0; i < 2; ++i)
	{
		ll nh = h + dy[i];
		ll nw = w + dx[i];


		if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
		if (field[nh][nw] != '#') continue;
		field[nh][nw] = '.';
		if (nh == H-1 && nw == W-1)
		{
			ll okk{true};
			for (ll hh = 0; hh < H; ++hh)
			{
				for (ll ww = 0; ww < W; ++ww)
				{
					if (field[hh][ww] == '#')
						okk = false;
				}
			}
			if (okk) ok = true;
			continue;
		}
		bfs(nh, nw);
		field[nh][nw] = '#';
	}
}

int main(int argc, char **argv)
{
	cin >> H >> W;
	for (ll h = 0; h < H; ++h)
		for (ll w = 0; w < W; ++w)
		{
			cin >> field[h][w];
		}
	field[0][0] = '.';
	bfs(0, 0);

	std::cout << (ok ? "Possible" : "Impossible")<< std::endl;
}

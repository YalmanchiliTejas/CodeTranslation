#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int N;
int L[50], T[50], R[50], B[50];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N)
	{
		if (N == 0) return 0;

		rep(i, 0, N) cin >> L[i] >> T[i] >> R[i] >> B[i];

		map<int, int> comp_x, comp_y;
		rep(i, 0, N)
		{
			comp_x[L[i]] = 0;
			comp_x[R[i]] = 0;
			comp_y[T[i]] = 0;
			comp_y[B[i]] = 0;
		}

		int idx = 0;
		for (auto p : comp_x)
		{
			comp_x[p.first] = idx;
			idx++;
		}

		idx = 0;
		for (auto p : comp_y)
		{
			comp_y[p.first] = idx;
			idx++;
		}

		ll G[105][105];
		rep(y, 0, 105) rep(x, 0, 105) G[y][x] = 0;

		rep(i, 0, N)
		{
			int l = comp_x[L[i]];
			int r = comp_x[R[i]];
			int t = comp_y[T[i]];
			int b = comp_y[B[i]];

			rep(y, b, t) rep(x, l, r)
			{
				G[y + 1][x + 1] |= 1LL << i;
			}
		}

		/*rep(y, 0, 10)
		{
			rep(x, 0, 10) cout << G[9 - y][x] << " ";
			cout << endl;
		}*/

		bool done[105][105];
		rep(i, 0, 105) rep(j, 0, 105) done[i][j] = false;
		int ans = 0;
		rep(y, 0, 105) rep(x, 0, 105) if (!done[y][x])
		{
			ll c = G[y][x];
			ans++;

			queue<int> que;
			que.push(y * 1000 + x);
			while (!que.empty())
			{
				int q = que.front(); que.pop();

				int y = q / 1000;
				int x = q % 1000;

				if (done[y][x]) continue;
				done[y][x] = true;

				rep(i, 0, 4)
				{
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || 105 <= yy) continue;
					if (xx < 0 || 105 <= xx) continue;
					if (G[yy][xx] != c) continue;
					if (done[yy][xx]) continue;

					que.push(yy * 1000 + xx);
				}
			}
		}

		cout << ans << endl;
	}
}
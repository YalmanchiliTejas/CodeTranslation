#include <bits/stdc++.h>
using namespace std;
#define mp(a, b) make_pair(a, b)
typedef long long ll;
const int INF = 1e9;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int maxn = 2000 + 10;
int n, a[3 * maxn];
int f[maxn][maxn], g[maxn], Max, delta;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) f[i][j] = f[j][i] = -INF;
	f[a[1]][a[2]] = f[a[2]][a[1]] = 0;
	for(int i = 1; i <= n; ++i) g[i] = -INF;
	g[a[1]] = g[a[2]] = 0;
	for(int i = 3; i < 3 * n; i += 3)
	{
		vector<piii> m;
		for(int j = 0; j < 8; ++j)
		{
			vector<int> b, c;
			for(int k = 0; k < 3; ++k)
			{
				if(j & (1 << k))
					b.push_back(a[i + k]);
				else
					c.push_back(a[i + k]);
			}
			if(b.size() == 0 && c[0] == c[1] && c[1] == c[2]) 
			{
				++delta;
				break;
			}
			else if(b.size() == 1)
			{
				if(c[0] == c[1]) for(int k = 1; k <= n; ++k) m.push_back(mp(mp(b[0], k), f[c[0]][k] + 1));
				for(int k = 1; k <= n; ++k) m.push_back(mp(mp(b[0], k), g[k]));
			}
			else if(b.size() == 2)
			{
				m.push_back(mp(mp(b[0], b[1]), f[c[0]][c[0]] + 1));
				m.push_back(mp(mp(b[0], b[1]), Max));
			}
		}
		for(auto v : m)
		{
			int x = v.first.first, y = v.first.second, val = v.second;
			f[x][y] = f[y][x] = max(f[x][y], val);
			g[x] = max(g[x], val);
			g[y] = max(g[y], val);
			Max = max(Max, val); 
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			ans = max(ans, f[i][j] + delta);
	ans = max(ans, f[a[3 * n]][a[3 * n]] + delta + 1);
	cout << ans << endl;
	return 0;
}
	
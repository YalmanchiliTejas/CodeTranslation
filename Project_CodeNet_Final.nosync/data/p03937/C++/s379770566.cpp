#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 100;
const ll inf = 2e18, mod = 1e9 + 7;

int h, w, d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char a[maxn][maxn];
bool vis[maxn][maxn];

bool isValid(int x, int y)
{
	if (0 <= x && x < h)
		return (0 <= y && y < w);
	return false;
}

void dfs(int x, int y)
{
	vis[x][y] = true;
	int nowx, nowy;
	for (int i = 0; i < 4; i++)
	{
		nowx = x + d[i][0];
		nowy = y + d[i][1];
		if (isValid(nowx, nowy) && !vis[nowx][nowy])
			dfs(nowx, nowy);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;
	for (int i = 0; i < h; i++)
		cin >> a[i];
	
	int cnt = 0, comp = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cnt += (a[i][j] == '#');
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (a[i][j] == '#' && !vis[i][j])
				dfs(i, j), comp++;
	cout << ((cnt == h + w - 1 && comp == 1) ? "Possible" : "Impossible") << endl;
}


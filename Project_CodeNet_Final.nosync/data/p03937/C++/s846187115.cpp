//Daniel Grzegorzewski
#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ST first
#define ND second

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

int n, m;
char a[10][10];
bool vis[10][10], res = true;

void dfs(int x, int y)
{
	vis[x][y] = true;
	if (a[x+1][y] == '#' && a[x][y+1] == '#')
		res = false;
	if (a[x-1][y] == '#' && !vis[x-1][y])
		res = false;
	if (a[x][y-1] == '#' && !vis[x][y-1])
		res = false;
	bool posz = false;
	if (x+1 <= n && a[x+1][y] == '#') {
		posz = true;
		dfs(x+1, y);
	}
	if (y+1 <= m && a[x][y+1] == '#') {
		posz = true;
		dfs(x, y+1);
	}
	if (!posz && (x != n || y != m))
		res = false;
}

int main()
{
    init_ios();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j)
    		cin >> a[i][j];
    }
    if (a[1][1] == '.') {
    	cout<<"Impossible\n";
    	return 0;
    }
    dfs(1, 1);
    if (res)
    	cout<<"Possible\n";
    else
    	cout<<"Impossible\n";
}
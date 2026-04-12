#include <iostream>
#include <queue>

using namespace std;

int n, m, dx[5] = { 0,1,0 }, dy[5] = { 0,0,1 };
char c[10][10];
bool vis[10][10] = { false };

void bfs()
{
	queue<pair<int, int> >Q;
	Q.push(make_pair(1, 1));
	vis[1][1] = true, c[1][1] = '.';
	while (!Q.empty())
	{
		int nowx = Q.front().first, nowy = Q.front().second, tmp = 0;
		for (int i = 1; i <= 2; i++)
		{
			int newx = nowx + dx[i], newy = nowy + dy[i];
			if (newx >= 1 && newy >= 1 && newx <= n && newy <= m && !vis[newx][newy] && c[newx][newy] == '#')
			{
				tmp++;
				Q.push(make_pair(newx, newy));
				vis[newx][newy] = true, c[newx][newy] = '.';
			}
			if (tmp == 2) return;
		}
		Q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	bfs();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == '#')
				return cout << "Impossible" << endl, 0;
	cout << "Possible" << endl;
	return 0;
}
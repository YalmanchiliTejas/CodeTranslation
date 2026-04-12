#include <bits/stdc++.h>
#define mp make_pair
#define PII pair <int, int>
#define x first
#define y second
using namespace std;
int n, m;
char a[10][10];
bool b[10][10];
int tot, cnt;
queue <PII> Q;

int solve (int i, int j)
{
	while (!Q.empty())
	{
		PII node = Q.front();
		Q.pop();
		int x = node.x + 1 , y = node.y;
		int xx = node.x, yy = node.y+1;
		if (x <= n && y <= m && a[x][y] == '#' && !b[x][y])
			Q.push(mp(x,y)), b[x][y] = 1;
		else if (xx <= n && yy <= m && a[xx][yy] == '#' && !b[xx][yy])
			Q.push(mp(xx,yy)), b[xx][yy] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '#' && !b[i][j]) return 0;
	return 1;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	Q.push(mp(1,1));
	b[1][1] = 1;
	cout << (solve(1,1) ? "Possible" : "Impossible");
    return 0;
}

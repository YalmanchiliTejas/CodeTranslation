#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 8;
int m,n;
char a[maxn+1][maxn+1];
bool visit[maxn+1][maxn+1];
void dfs(int x,int y)
{
	visit[x][y]=true;
	if (x<m and !visit[x+1][y] and a[x+1][y]=='#') dfs(x+1,y);
	else
	if (y<n and !visit[x][y+1] and a[x][y+1]=='#') dfs(x,y+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> m >> n;
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	cin >> a[i][j];
	memset(visit,false,sizeof(visit));
	dfs(1,1);
	/*for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		cout << visit[i][j];
		cout << '\n';
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		cout << a[i][j];
		cout << '\n';
	}*/
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	if (a[i][j]=='#' and !visit[i][j])
	{
		cout << "Impossible";
		return 0;
	}
	cout << "Possible";
	return 0;
}
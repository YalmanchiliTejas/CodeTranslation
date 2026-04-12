#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define INF (long)1e9
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
using namespace std;
typedef long long ll;
bool table[10][10];
int dfs(int pos, int n, bool visited[10])
{
	bool ok = true;
	for(int i = 0; i < n; i++)
	{
		if(visited[i] == false) ok = false;
	}
	if(ok) return 1;
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		if(visited[i] == true) continue;
		if(table[pos][i] == false) continue;
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;
		table[a][b] = table[b][a] = true;
	}
	bool visited[n + 1];
	for(int i = 0; i < n + 1; i++)
	{
		visited[i] = false;
	}
	visited[0] = true;
	int ans = dfs(0, n, visited);
	cout << ans << endl;
	return 0;
}
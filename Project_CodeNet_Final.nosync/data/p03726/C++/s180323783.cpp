#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
bool flag[100000];
bool ans = true;
int dfs(int node)
{
	if (flag[node])return 0;
	flag[node] = true;
	int c = 0;
	for (int i = 0; i < pat[node].size(); i++)c += dfs(pat[node][i]);
	if (c >= 2)ans = false;
	return c ^ 1;
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	printf((1 - dfs(0)) && ans ? "Second\n" : "First\n");
}
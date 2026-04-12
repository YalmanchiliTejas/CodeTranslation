#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

const int maxn = 1E5 + 10;

int n;
bool vis[maxn];

vector <int> v[maxn];

inline void Dfs(int x,int from)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		int to = v[x][i];
		if (to == from) continue;
		Dfs(to,x); if (vis[to]) continue;
		if (vis[x]) {puts("First"); exit(0);}
		vis[x] = vis[to] = 1;
	}
}

int main()
{
	#ifdef DMC
		freopen("DMC.txt","r",stdin);
	#endif
	
	cin >> n;
	if (n & 1) {puts("First"); return 0;}
	for (int i = 1; i < n; i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		v[x].push_back(y); v[y].push_back(x);
	}
	Dfs(1,0); puts("Second");
	return 0;
}
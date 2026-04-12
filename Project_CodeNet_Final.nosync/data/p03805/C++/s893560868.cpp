#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<cstring>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int> 
#define N (1<<7)

int n,m,ans;
vector<int>edge[10];
bool vis[10];

bool check()
{
	REP(i,n)if(!vis[i])return false;
	return true; 
}

void dfs(int x,int l)
{
	if(l==n)
	{
		if(check())ans++;
		return;
	}
	rep(i,edge[x].size())
	{
		int y=edge[x][i];
		if(vis[y])continue;
		vis[y]=true;
		dfs(y,l+1);
		vis[y]=false;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v); 
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vis[1]=true;
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
/*
3 3
1 2
1 3
2 3
*/
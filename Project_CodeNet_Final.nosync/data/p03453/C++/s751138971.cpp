#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
//#include <unordered_set>
//#include <unordered_map>
//#include <bits/stdc++.h>

#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define fi first
#define se second
#define int ll

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod eps=1e-11;
const lod pi=acos(-1);
const int oo=1<<30;
const ll loo=1ll<<62;
const int mods=1e9+7;
const int MAXN=600005;
const int INF=0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
priority_queue<PR> que;
vector<PR> e[MAXN];
int fu[MAXN],fv[MAXN],su[MAXN],sv[MAXN],flag[MAXN],n,m,S,T;
void getdist(int *f,int *s,int S,int T)
{
	for (int i=1;i<=n;i++) f[i]=loo,flag[i]=0;
	que.push(MP(0,S)),f[S]=0,s[S]=1;
	while (!que.empty())
	{
		int q=que.top().se,c=-que.top().fi; que.pop();
		if (flag[q]) continue; flag[q]=1;
		for (auto v:e[q])
			if (f[v.fi]>c+v.se) 
				s[v.fi]=s[q],f[v.fi]=c+v.se,que.push(MP(-f[v.fi],v.fi));
			else if (f[v.fi]==c+v.se) (s[v.fi]+=s[q])%=mods;
	}
}
signed main()
{
	n=read(),m=read(),S=read(),T=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),c=read();
		e[u].PB(MP(v,c)),e[v].PB(MP(u,c));
	}
	getdist(fu,su,S,T);
	getdist(fv,sv,T,S);
	
	int D=fu[T],ans=0;
	for (int i=1;i<=n;i++) 
		if (fu[i]*2==D&&fv[i]*2==D)
		{
			int t=su[i]*sv[i]%mods;
			ans+=t*(t-1)%mods;
		}
	for (int i=1;i<=n;i++)
		for (auto v:e[i])
		if (i<v.fi)
		{
			int x=i,y=v.fi,c=v.se;
			if (fu[x]>fu[y]) swap(x,y);
			if (fu[x]*2<D&&fv[y]*2<D&&fu[x]+fv[y]+v.se==D) 
			{
				int t=su[x]*sv[y]%mods;
				ans+=t*(t-1)%mods;
			}
		}
	ans%=mods;
	printf("%lld\n",(su[T]*(su[T]-1)-ans+mods)%mods);
	return 0;
}
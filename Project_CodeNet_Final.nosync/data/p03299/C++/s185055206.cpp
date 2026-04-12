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
const int MAXN=205;
const int INF=0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
vector<PR> e[MAXN];
int a[MAXN],f[MAXN][MAXN],g[MAXN][MAXN],b[MAXN];
int upd(int x,int y){ return x+y>=mods?x+y-mods:x+y; }
int quick_pow(int x,int y)
{
	int ret=1;
	for (;y;y>>=1)
	{
		if (y&1) ret=1ll*ret*x%mods;
		x=1ll*x*x%mods;
	}
	return ret;
}
int main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for (int i=1,lst=0;i<=n;i++)
	{
		b[i]--;
		if (b[i]!=b[i-1]) 
		{
			int id=-1;
			for (int j=1;j<=n;j++)
				if (a[j]-1>=b[i]&&a[j-1]-1<b[i]) id=j;
				else if (a[j-1]-1>=b[i]&&a[j]-1<b[i]) e[j-1].PB(MP(id,b[i]-lst)),id=-1;
			if (id>0) e[n].PB(MP(id,b[i]-lst));
			lst=b[i];
		}
	}
//	for (int i=1;i<=n;i++)
//		for (auto k:e[i]) cout<<k.fi<<" "<<i<<":"<<k.se<<endl;
	f[0][0]=2;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=i-1;j++) f[i][1]=upd(f[i][1],f[i-1][j]);
		for (auto k:e[i]) 
			if (k.fi==i) f[i][1]=1ll*f[i][1]*quick_pow(2,k.se)%mods;
		for (int j=2;j<=i;j++)
		{
			f[i][j]=upd(f[i][j],f[i-1][j-1]);
			for (auto k:e[i])
				if (k.fi>=i-j+1) f[i][j]=1ll*f[i][j]*quick_pow(2,k.se)%mods;
		}
//		cout<<i<<":";
//		ll sum=0;
//		for (int j=0;j<=i;j++) cout<<f[i][j]<<" ",sum+=f[i][j];
//		cout<<sum<<endl;
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=upd(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
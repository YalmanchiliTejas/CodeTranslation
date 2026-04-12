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
const int MAXN=3005;
const int INF=0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
int fac[MAXN],inv[MAXN],S[MAXN][MAXN],n,mods;
int C(int x,int y) { return 1ll*fac[x]*inv[y]%mods*inv[x-y]%mods; }
inline int quick_pow(int x,int y,int mods)
{
	int ret=1;
	for (;y;y>>=1)
	{
		if (y&1) ret=1ll*ret*x%mods;
		x=1ll*x*x%mods;
	}
	return ret;
}
inline int upd(int x,int y) { return x+y>=mods?x+y-mods:x+y; }
void Init(int n)
{
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mods;
	inv[n]=quick_pow(fac[n],mods-2,mods);
	for (int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mods;
	
	S[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++) S[i][j]=upd(S[i-1][j-1],1ll*S[i-1][j]*j%mods);
}
int main()
{
	n=read(),mods=read(); 
	Init(n+1);
	int ans=0;
	for (int i=0;i<=n;i++)
	{
		int t=0;
		for (int j=0;j<=i;j++) t=upd(t,1ll*S[i+1][j+1]*quick_pow(2,(n-i)*j,mods)%mods);
		t=1ll*t*C(n,i)%mods*quick_pow(2,quick_pow(2,n-i,mods-1),mods)%mods;
		ans=(i&1)?upd(ans,mods-t):upd(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}

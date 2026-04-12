//#include<bits\stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<algorithm>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#define ll long long
#define db double
#define INF 1000000000
#define ldb long double
#define pb push_back
#define get(x) x=read()
#define gt(x) scanf("%d",&x)
#define put(x) printf("%d\n",x)
#define putl(x) printf("%lld\n",x)
#define gc(a) scanf("%s",a+1)
#define rep(p,n,i) for(RE ll i=p;i<=n;++i)
#define go(x) for(ll i=lin[x],tn=ver[i];i;tn=ver[i=nex[i]])
#define fep(n,p,i) for(RE ll i=n;i>=p;--i)
#define pii pair<ll,ll> 
#define mk make_pair
#define RE register
#define P 1000000007
#define S second
#define gf(x) scanf("%lf",&x)
#define pf(x) ((x)*(x))
#define ull unsigned long long
#define mod 998244353
using namespace std;
char buf[1<<15],*fs,*ft;
inline char getc()
{
    return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline ll read()
{
    register ll x=0,f=1;register char ch=getc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getc();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getc();}
    return x*f;
}
const ll MAXN=200005;
ll n;
ll a[MAXN];
ll f[MAXN][3];//f[i][j]前表示前i个数用掉j个空隙的最大值.
signed main()
{
	//freopen("1.in","r",stdin);
	get(n);
	rep(1,n,i)get(a[i]);
	memset(f,0xcf,sizeof(f));
	f[0][0]=0;f[1][0]=a[1];
	rep(2,n,i)
	{
		f[i][0]=f[i-2][0]+a[i];
		if(i>=3)f[i][1]=max(f[i-3][0]+a[i],f[i-2][1]+a[i]);
		if(i>=4)f[i][2]=max(f[i-4][0]+a[i],max(f[i-3][1]+a[i],f[i-2][2]+a[i]));
	}
	if(n&1)putl(max(max(f[n][1],f[n][2]),max(f[n-2][0],max(f[n-1][0],f[n-1][1]))));
	else putl(max(f[n][1],max(f[n][0],f[n-1][0])));
	return 0;
}

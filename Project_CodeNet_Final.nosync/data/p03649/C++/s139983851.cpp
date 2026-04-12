#include <bits/stdc++.h>
#include <unordered_map>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define D(x) cout << #x << " = " << x << endl
#define DD(x,y) cout << #x << " = " << x << " " << #y << " = " << y << endl
#define Max 300005
#define PI 3.141592653589793
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define mod 1000000007
#define INF (LL)1e18

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL bigmod(LL b,LL p)
{
    if(p == 0)return 1;
    LL my = bigmod(b,p/2);
    my*=my;
    my%=mod;
    if(p & 1)my*=b,my%=mod;
    return my;
}
int setb(int n,int pos)
{
    return n=n | (1 << pos);
}
int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}
bool checkb(int n,int pos)
{
    return (bool)(n & (1 << pos));
}

LL ara[100],n;

LL F()
{
	LL ret = 0;
	while(1)
	{
		sort(ara+1,ara+n+1);
		if(ara[n] < n)break;
		LL need = ara[n] - (n-1);
		LL item = need / n;
		if(need % n)item++;
		ara[n] -= (n * item);
		for(LL i = 1; i < n; i++)ara[i] += item;
		ret += item;
	}
	return ret;
}

int main()
{
	//FI;
	LL i;
	sl(n);
	rep(i,n)sl(ara[i]);
	LL ret = F();
	pl(ret); NL;
	return 0;
}

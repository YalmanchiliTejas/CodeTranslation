#include<bits/stdc++.h>
#define pf printf
#define sc(x) scanf("%d",&x);
#define scs(x) scanf("%s",x);
#define scl(x) scanf("%lld",&x);
#define rep(i,s,e) for(int i=s; i<=e; ++i)
#define dep(i,s,e) for(int i=s; i>=e; --i)
typedef long long ll;
using namespace std;
const ll mod=998244353;
ll a[10005];
int main()
{
	ll n,s,count=0;
	scl(n);scl(s);
	rep(i,1,n){
		ll u;scl(u);a[0]=i;
		if(u<=s)dep(j,s-u,0)(a[j+u]+=a[j])%=mod;
		(count+=a[s]%mod*(n-i+1)%mod)%=mod;a[s]=0;
	}pf("%lld\n",count%mod);
}

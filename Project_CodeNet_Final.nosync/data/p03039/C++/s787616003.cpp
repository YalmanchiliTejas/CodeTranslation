#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<61);
const int inf=(1<<30);
const int nmax=2e5+50;
const ll mod=1e9+7;
using namespace std;
ll f[nmax],invf[nmax],n,m,k,i,x,ans;
ll pw(ll n,ll p)
{
    ll tmp=n,ans=1;
    for(int i=0;i<=32;i++)
    {
        if(p&(1LL<<i))ans=(ans*tmp)%mod;
        tmp=(tmp*tmp)%mod;
    }
    return ans;
}
void pre1()
{
    f[0]=invf[0]=1;
    for(ll i=1;i<=2e5;i++)
    {
        f[i]=(f[i-1]*i)%mod;
        invf[i]=pw(f[i],mod-2);
    }
}
ll nck(int x,int y)
{
    if(y>x || y<0)return 0LL;
    if(!y)return 1LL;
    return (((f[x]*invf[y])%mod)*invf[x-y])%mod;
}
int main()
{
    //freopen("sol.in","r",stdin);
    //freopen("sol.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    pre1();
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		x=i*(i-1)/2LL%mod*m%mod*m%mod*nck(n*m-2,k-2)%mod;
		ans=(ans+x)%mod;
	}
	for(i=1;i<=m;i++)
	{
		x=i*(i-1)/2LL%mod*n%mod*n%mod*nck(n*m-2,k-2)%mod;
		ans=(ans+x)%mod;
	}
	cout<<ans<<endl;
    return 0;
}
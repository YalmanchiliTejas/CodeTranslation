#include <bits/stdc++.h>
using namespace std;
#define fst ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endk cout<<"\n";
typedef long long int ll;
typedef long int l;
#define l(i,a,b) for(i=a;i<b;i++)
#define lo(i,a,b) for(i=a;i>=b;i--)
#define s(v) sort(v.begin(),v.end());
#define pb push_back;
#define vll vector<ll>
#define vint vector<int>
#define test() ll t;cin>>t;while(t--){solve();};
#define test1() int t=1;while(t--){solve();};
bool isPrime(ll x)
{
    ll i,n;
    n=sqrt(x);
    if(x==1) return false;
    if(x==2 || x==3) return true;
    for(i=2;i<=n;i++)
    {
        if(!(x%i)) return false;
    }
    return true;
}
ll power(ll x,ll y)
{
	ll ans=1;
	while(y>0)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y=y>>1;
	}
	return ans;
}
int solve()
{
    ll n,i,ans=0,j;
    cin>>n;
    vll v(n),x(n,0);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(i=n-2;i>=0;i--)
    {
        x[i]=(x[i+1]+v[i+1])%1000000007;
    }
    for(i=0;i<n;i++)
    {
        ans=(ans+(v[i]*x[i])%1000000007)%1000000007;
    }
    cout<<ans;
    return 0;
}
int main()
{
    fst;
    test1();
    return 0;
}
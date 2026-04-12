/* ****mittal**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
ll add(ll x,ll y)
{
return (x%hell+y%hell)%hell;
}
ll mul(ll x,ll y)
{
return ((x%hell)*(y%hell))%hell;
}
ll sub(ll x,ll y)
{
return (x-y+hell)%hell;
}
#define N  100005
ll binpow(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
 //  cin>>t;
    for(int ok=1;ok<=t;ok++)
    {
        ll n;
        cin>>n;
        ll op=0;
        ll oq=0;
        for(int i=0;i<n;i++)
        {
        	ll x;
        	cin>>x;
        	op=(op+(x*x)%hell)%hell;
        	oq=(oq+x)%hell;
        }
        oq=(oq*oq)%hell;
        oq=(oq-op+hell)%hell;
        ll o=binpow(2,hell-2,hell);
        cout<<(oq*o)%hell<<endl;

     
    }
    return 0;
}
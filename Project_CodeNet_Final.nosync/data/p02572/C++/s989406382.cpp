/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  100005
ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
int main()
{
	
	io
	
	ll n;
	cin>>n;
	std::vector<ll> a(n);
	ll ts=0;
	rep(i,0,n)
	{
		cin>>a[i];
		ts+=a[i];
		ts%=hell;
	}
	ts%=hell;
	ll res=0;
	rep(i,0,n)
	{
		res=(res%hell+((a[i]%hell)*((ts-a[i]+hell)%hell))%hell)%hell;
	}
	res=(res*(expo(2,hell-2,hell))%hell)%hell;
	cout<<res;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define N 2*10e5
#define precise cout<<fixed<<setprecision(10)
#pragma GCC optimize("O0")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")
#define rep(i,a,b) for(int i=a;i<b;i++)
#define min3(a,b,c) min(a,min(b,c))
#define nl cout<<"\n";
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define mod 1000000007
typedef long long ll;
typedef vector<long long> vl;
typedef vector<pair<long,long>> vp;
void get(ll arr[],ll n){for(ll i=0;i<n;i++) cin>>arr[i];}
ll gcd(ll a,ll b);
ll binpow(ll a,ll b);
void solve()
{
    ll n;
    cin>>n;
    ll a[n];get(a,n);
    ll sum=0;
    rep(i,0,n) sum= (sum + a[i])%mod;
    sum = sum%mod;
    ll ans=0;
    rep(i,0,n)
    {
        ans = (ans + ((sum - a[i] + mod)%mod)*a[i])%mod;
    }
    if(ans%2==0)
    ans = ans/2;
    else
    {
        ans= ans+mod;
        ans= ans/2;
    }
    cout<<ans;   
}
int main()
{
 	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	t=1;
	//cin>>t;
	while(t--)
	{
	 	solve();
	}
	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
ll binpow(ll a, ll b) {
   ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
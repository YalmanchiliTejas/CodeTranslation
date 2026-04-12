/*
Author: Babin Dutta
*/
 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,n) for(int i=0;i<n;i++)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
//#define endl "\n"
#define mm 998244353
 
ll power(ll x, ll y, ll p)
{
    ll res = 1;  
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}
ll modInverse(ll A,ll M)
{
    return power(A,M-2,M);
}

void solve(){
	int n; cin>>n;
	ll a[n], b[n];
	f(i,n) cin>>a[i];
	b[n-1] = a[n-1];
	for(int i=n-2;i>=0;i--) b[i] = (a[i] + b[i+1])%mod;
	ll ans = 0;
	for(int i=0;i<n-1;i++){
		ll tmp = (a[i] * b[i+1])%mod;
		ans = (ans+tmp)%mod;
	}
	cout<<ans<<endl;
}
 
int main(){
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	boost;
	int t=1; //cin>>t;
	for(int i=1;i<=t;i++) solve();
	return 0;
}
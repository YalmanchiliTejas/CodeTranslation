#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
 
#define mo 1000000007
#define inf 1e18
#define rep(i, s, n) for (ll i = s; i < n; i = i + 1)
#define rrep(i,s,n) for(ll i=s;i>=n;i--)

ll mod(ll n) { return (n % (ll)mo + (ll)mo)%(ll)mo;}


int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	
	rep(i,0,n) cin>>a[i];
	
	vector<ll> p(n);
	p[0] = a[0];
	rep(i,1,n) p[i] = p[i-1] + a[i];
	ll ans = 0;
	rep(i,0,n){
		ll temp = mod(a[i]*mod(p[n-1]-p[i]));
		ans = mod(ans+temp);
	}
	cout<<ans;
	
	
}
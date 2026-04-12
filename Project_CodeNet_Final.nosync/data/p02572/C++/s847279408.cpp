#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
using namespace std;

void solve(int test){
	ll n;
	cin>>n;
	ll a[n], sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum += a[i];
		sum %= mod;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		sum = (sum - a[i] + mod) % mod;
		ans += (a[i] * sum) % mod;
		ans %= mod;
	}
	cout<<ans;
}
  
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t=1,k;
	//cin>>t;
	k = t;
	while(t--){
		solve(k - t);
	}
	cerr<<"Timpe elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " mps\n" ;
	return 0;
}
#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
ll a[N];
void solve(){
	int n; 
	cin>>n; 
	ll sum = 0;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ll x; 
		cin>>x; 
		ans+=x*sum;
		ans%=mod;
		sum+=x;
		sum%=mod;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}

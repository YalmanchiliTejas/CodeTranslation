#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll P = 1e9+7;



int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	// cin>>t;

	while(t--){
		ll n;
		cin>>n;

		vector<ll> v(n),p(n);
		for(ll i=0;i<n;++i) cin>>v[i];

		p = v;
		for(ll i=p.size()-2;i>=0;--i) p[i] = (p[i] + p[i+1])%P;
		ll ans = 0;
		for(ll i=0;i<n-1;++i){
			ans += (v[i]*(p[i+1])) % P;
			ans %= P;
		}

		cout<<ans<<"\n";
	}	

	return 0;
}
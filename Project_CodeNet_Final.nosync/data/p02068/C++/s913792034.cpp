#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main()
{
	ll n; cin>>n;
	map<ll, ll> m;
	rep(i, n){
		ll a; cin>>a;
		ll ao = a;
		for(int j=2; j*j<=a; j++){
			if (a%j==0){
				m[j] += ao;
				while(a%j==0) a/=j;
			}
		}
		if (a!=1) m[a]+=ao;
	}
	ll ans=0;
	for(auto it=m.begin(); it!=m.end(); it++){
		ans = max(ans, it->second);
	}
	cout << ans << "\n";
	return 0;
}

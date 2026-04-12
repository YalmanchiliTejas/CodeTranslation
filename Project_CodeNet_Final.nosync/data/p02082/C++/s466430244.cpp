#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main(){
	ll s, t; cin>>s>>t;
	ll p, q, M; cin>>p>>q>>M;
	ll y; cin>>y;
	ll a = 0;
	ll ans = y;
	for(int i=1;i<1e8;i++) {
		a = (a*p+q) % M;
		ans = ans ^ a;

	}
	cout << ans << "\n";
	return 0;
}

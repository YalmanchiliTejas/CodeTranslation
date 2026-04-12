#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	ll s, t; cin>>s>>t;
	ll p, q, M; cin>>p>>q>>M;
	ll y; cin>>y;

	const ll MAX = 1e8;

	ll ans = y;
	ll a = 0;
	for(int i=1;i<MAX;i++){
		a = (a*p+q)%M;
		ans = ans xor a;
	}
	cout << ans << "\n";
	return 0;
}

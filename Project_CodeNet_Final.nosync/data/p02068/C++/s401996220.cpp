#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	ll n; cin>>n;
	map<ll, ll> sums;
	for(int i=0; i<n; i++){
		ll a; cin>>a;
		ll oa = a;
		for(int j=2; j*j<=a; j++){
			if (a%j==0){
				sums[j] += oa;
				while(a%j==0) a/=j;
			}
		}
		if (a!=1) sums[a] += oa;
	}
	ll ans=0;
	for(auto it=sums.begin(); it!=sums.end(); it++){
		ans = max(ans, it->second);
	}
	cout << ans << endl;
	return 0;
}

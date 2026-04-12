#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll mod = 1e9+7;

int main() {
	ll n;
	cin>>n;
	ll a[n],i,s=0;
	for(i=0;i<n;i++) {
		cin>>a[i];
		s+=a[i];
	}
	ll t[n];
	for(i=0;i<n;i++) {
		t[i] = (s-a[i]);
		if(t[i]<0)
			t[i] += mod;
		t[i] %= mod;
		s -= a[i];
		if(s<0)
			s+=mod;
		s %= mod;
	}
	ll ans =0;
	for(i=0;i<n;i++) {
		ll temp = ((a[i]%mod) * (t[i]%mod))%mod;
		ans += temp;
		if(ans<0)
			ans += mod;
		ans %= mod;
	}
	cout<<ans;
	return 0;
}
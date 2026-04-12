#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n; cin >> n;
    vector<ll> a(n);

	for (ll i = 0;i < n;i++){
		cin >> a[i];
	}	

	sort(a.begin(),a.end());

	ll ans = 0;

	vector<ll> tmp(n);
	tmp[0] = a[n-1];
	for (ll i = 1;i < n-1;i++){
		if(i%2 == 0){
			tmp[i] = a[n-1-i/2];
			ans += abs(tmp[i] - tmp[i-1]);
		}else{
			tmp[i] = a[(i+1)/2 - 1];
			ans += abs(tmp[i] - tmp[i-1]);
		}
		//cout <<  ans <<  endl;
	}

	//ans += abs(tmp[0]-a[(n-2)/2]);
	
	ll s = abs(tmp[0] - a[(n-1)/2]);
	ll t = abs(tmp[n-2] - a[(n-1)/2]);
	if(s > t) ans += s;
	else ans += t;

	ll ans2 = 0;
	reverse(a.begin(),a.end());
	tmp[0] = a[n-1];
	for (ll i = 1;i < n-1;i++){
		if(i%2 == 0){
			tmp[i] = a[n-1-i/2];
			ans2 += abs(tmp[i] - tmp[i-1]);
		}else{
			tmp[i] = a[(i+1)/2 - 1];
			ans2 += abs(tmp[i] - tmp[i-1]);
		}
		//cout <<  ans <<  endl;
	}

	//ans += abs(tmp[0]-a[(n-2)/2]);
	
	s = abs(tmp[0] - a[(n-1)/2]);
	t = abs(tmp[n-2] - a[(n-1)/2]);
	if(s > t) ans2 += s;
	else ans2 += t;

	cout << max(ans,ans2) << endl;

	return 0;

}

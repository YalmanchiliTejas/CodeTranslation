#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

typedef pair<ll,ll> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n; cin >> n;
	ll d[200005];
	map<ll,P> mp;

	ll sum = 0;
	ll s[200005];

	mp[0] = P(1,1);
	for (int i = 0;i < n;i++){
		cin >> d[i];
		sum += d[i];
		s[i] = sum;
		P p = mp[sum];
		if(p.first == 0)mp[sum].first = mp[sum].second  =  i+2;
		else mp[sum].second = i+2;
	}

	ll ans = -1;

	for (auto&& var : mp) {
		ll tmp = var.second.second - var.second.first;
		ans = max(ans,tmp);
	}

	cout << ans << endl;

	return 0;

}


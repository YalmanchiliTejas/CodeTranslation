#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll N, X , M;
	cin >> N >> X >> M;
	vector<ll> cnt(M, -1);
	vector<ll> v;
	ll a = X%M;
	v.push_back(a);
	cnt[a] = 0;
	ll p = -1;
	for(int i=1; i<N; i++) {
		a = (a*a)%M;	
		if (cnt[a] != -1) {
			p = i - cnt[a];
			break;
		}
		cnt[a] = i;
		v.push_back(a);
	}

	ll ans = 0;
	if (p == -1) {
		for (ll i: v) ans += i;
	}
	else {
		for(int i = 0; i<cnt[a]; i++) ans += v[i];
		ll tot = 0;
		for(int i = cnt[a]; i<v.size(); i++) tot += v[i];
		ll n = N - cnt[a];
		ans += tot*(n/p);
		ll m = N - cnt[a] - p*(n/p);
		for(int i=cnt[a]; i<cnt[a]+m; i++) ans += v[i];
	}
	cout << ans << endl;

	return 0;
}


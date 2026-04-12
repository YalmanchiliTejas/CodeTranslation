#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, x, m;
	cin >> n >> x >> m;
	if(m == 0 || x == 0) return cout << 0, 0;
	ll ans = 0;
	ll a = x % m;
	vector <ll> v; set <ll> s;
	while(n > 0) {
		if(s.find(a) != s.end()) break;
		ans += a;
		v.push_back(a); s.insert(a);
		a = (a * a) % m;
		n --;
	}
	if((int) v.size() > 0 && n > 0) {
		reverse(v.begin(), v.end());
		while(v.back() != a && (int) v.size()) v.pop_back();
		reverse(v.begin(), v.end());
		ll fp = n / ((int) v.size());
		n -= fp * ((int) v.size());
		ans += fp * accumulate(v.begin(), v.end(), 0LL);
		for(int i = 0; i < n; i ++) ans += v[i];
	}
	cout << ans;
	
	return 0;
}
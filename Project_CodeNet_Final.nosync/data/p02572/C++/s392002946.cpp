#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long int
using namespace std;

const ll mod = 1000000007;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	ll s = 0, ss = 0;
	for (auto &x : a) {cin >> x; s = (s + x) % mod; ss = (ss + (x * x)) % mod;}
	s = (s * s) % mod;
	cout << (((s - ss + mod) % mod) * 500000004) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}

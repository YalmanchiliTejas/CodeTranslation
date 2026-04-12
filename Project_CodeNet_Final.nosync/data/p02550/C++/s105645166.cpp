#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, x, m; cin >> n >> x >> m;
	int cycle = 0;
	x %= m;
	map<ll, int> mapp;
	vector<ll> temp;
	while (mapp[x] == 0) {
		cycle++;
		temp.push_back(x);
		mapp[x] = cycle;
		if (cycle == n) {cout << accumulate(temp.begin(), temp.end(), 0ll); return ;}
		x = x * x % m;
	}
	if (x == 0) {
		cout << accumulate(temp.begin(), temp.end(), 0ll);
		return ;
	}
//	for (auto u : temp)cout << u << ' '; cout << endl;
	n -= mapp[x] - 1;
	ll cur = n / (cycle - mapp[x] + 1);
	n %= (cycle - mapp[x] + 1);
	ll ans = 0;
	for (int i = 0; i < mapp[x] - 1; i++)ans += temp[i];
	ll wow = 0, all = 0;
	if (mapp[x] - 1 >= 0)for (int i = mapp[x] - 1 ; i <= cycle; i++) {
			if (i <= n + mapp[x] - 2)wow += temp[i];
			all += temp[i];
		}
	ans += all * cur;
	//for (auto u : temp)cout << u << ' '; cout << endl;
	//cout << mapp[x] - 2 + n  << endl;
	ans += wow;
	cout << ans;



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin >> t;
	// while (t--)
	solve();

}
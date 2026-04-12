// you should probably see at the bottom ..
#include<bits/stdc++.h>

#ifdef LOCAL
#include "prabh.hpp"
#endif

#define int long long
#define pb push_back
#define range(v) v.begin(),v.end()
#define rrange(v) v.rbegin(), v.rend()
#define mod (int)(1e9 + 7)
#define inf (int)(1e15)
#define N (int)(2e5 + 10)

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	int ans = 0;
	int pref = 0;
	for (int &i : a) {
		ans += (pref * i) % mod, ans %= mod;
		pref += i, pref %= mod;
	}

	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);
	int t_c = 1;
//	cin >> t_c;
	while (t_c--)
		solve();
}

/*
 * COME ON DUDE .... DONT GET UP UNTIL U GET THE SOLUTION
 * GIVING UP NOT GONNA HELP .. JUST GET YOUR ASS TO WORK ALREADY ..
 * AND FOR FUCKING SAKE ... DONT PANIC !!
*/

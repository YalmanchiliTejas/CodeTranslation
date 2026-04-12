#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main()
{
	//freopen("input.txt", "r", stdin);
	IOS;
	
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x: a) cin >> x;

	const int MOD = 1e9 + 7;

	int sum = 0;
	for(auto x: a) {
		sum = (sum + x)%MOD;
	}

	int ans = 0, prev = 0;
	for(auto x: a) {
		prev = (prev + x)%MOD;
		ans = (ans + (x * (sum - prev + MOD))%MOD)%MOD;
	}

	cout << ans << '\n';
	return 0;
}
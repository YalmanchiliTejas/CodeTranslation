//FINISH WHAT YOU START!
#include<bits/stdc++.h>

#define fileIO freopen("input.txt", "r", stdin); freopen("output1.txt", "w", stdout);
#define IOS ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define inf ((long long) 1e18 )
#define mod 1000000007
#define int long long
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define debug(x) cout << '>' << #x << ':' << x << '\n';
#define debug2(x,y) cout << '>' << #x << " = " << x << " & "<< #y <<" = "<< y << '\n';

using namespace std;

const int N = 1e5 + 7;

int32_t main() {
	IOS
#ifndef ONLINE_JUDGE
	fileIO
#endif
	auto start = std::chrono::high_resolution_clock::now();
	int test;
	test = 1;
	// cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int a[n];
		for (auto &i : a)
			cin >> i;
		int pre[n] = {0};
		pre[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0 ; i--)
			pre[i] = (a[i] + pre[i + 1]) % mod;
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans = (ans + (a[i] * pre[i + 1]) % mod ) % mod;
		}
		cout << ans << endl;
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	cerr << "Time taken : " << ((long double)duration.count()) / ((long double) 1e9) << "s " << endl;

	return 0;
}

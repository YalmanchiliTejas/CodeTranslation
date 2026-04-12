#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = 0;
	vector<int> suffix(n, 0);
	suffix[n - 1] = arr[n - 1] % mod;
	for (int i = n - 2; i >= 0; i--) {
		suffix[i] = (suffix[i + 1] + arr[i]) % mod;
	}
	for (int i = 0; i < n - 1; i++)
		sum = (sum + (suffix[i + 1] * arr[i]) % mod) % mod;
	cout << sum % mod;
	return 0;
}
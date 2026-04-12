#include <bits/stdc++.h>

#define FAST_IO                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);

#define debug(a) cout << #a << " " << a << endl;
#define _debug(a, i) cout << #a << "[" << i << "]" << " = " << a[i] << endl;

using namespace std;

using ll = long long;

const int MOD = 998244353;
const ll INF_LLONG = 1e18 + 9;
const int INF_INT = 1e9 + 9;

template<typename T>
unsigned int index_of_max(vector<T>& arr) {
	unsigned int idx = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] > arr[idx])
			idx = i;
	}
	return idx;
}

template<typename T>
unsigned int index_of_min(vector<T>& arr) {
	unsigned int idx = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] < arr[idx])
			idx = i;
	}
	return idx;
}

bool isPalindrome(string s, int l, int r) {
	for (; l <= r; ++l, --r) {
		if (s[l] != s[r])
			return false;
	}
	return true;
}

int main()
{
	//	#ifndef ONLINE_JUDGE
	//		(void)freopen("input.txt", "r", stdin);
	//		(void)freopen("output.txt", "w", stdout);
	//	#endif	
	FAST_IO;
	int n, S;
	cin >> n >> S;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<ll> dp(3001);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		dp[0] += 1;
		for (int j = S; j >= 0; --j) {
			if (j + a[i] <= S) {
				dp[j + a[i]] += dp[j];
				dp[j + a[i]] %= MOD;
			}
		}
		ans += dp[S];
		ans %= MOD;
	}
	cout << ans;
	return 0;
}



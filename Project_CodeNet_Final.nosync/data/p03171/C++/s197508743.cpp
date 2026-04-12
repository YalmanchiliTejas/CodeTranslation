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

const int MAXN = 3005;
ll dp[MAXN][MAXN];

int main()
{
	//	#ifndef ONLINE_JUDGE
	//		(void)freopen("input.txt", "r", stdin);
	//		(void)freopen("output.txt", "w", stdout);
	//	#endif	
	FAST_IO;
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto& x : a)
		cin >> x;
	// dp[0][n-1]
	for (int L = n-1; L >= 0; --L) {
		for (int R = L; R < n; ++R) {
			if (L == R)
				dp[L][R] = a[L];
			else
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
		}
	}
	cout << dp[0][n - 1];
	return 0;
}



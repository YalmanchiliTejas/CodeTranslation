#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int maxn = 1e5 + 7;
const int inf = 2e9 + 7;
const ll infl = 1e18 + 7;
const long double eps = 1e-9;
const ll mod = 1e9 + 7;

ll dp[(int)1e4 + 7][107][10];

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // _DEBUG

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int d;
	cin >> s >> d;
	/*if (d == 1) {
		ll ans = 0;
		for (int i = 0; i < s.size(); i++) {
			ans = ((ans * 10) % mod + s[i] - '0') % mod;
		}
		cout << ans;
		return 0;
	}*/
	for (int i = 0; i < 10; i++) {
		dp[0][i % d][i]++;
	}
	int n = s.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 0; k < 10; k++) {
				for (int q = 0; q < 10; q++) {
					dp[i + 1][(j + q) % d][q] = (dp[i + 1][(j + q) % d][q] + dp[i][j][k]) % mod;
				}
			}
		}
	}
	reverse(s.begin(), s.end());
	ll ans = 0, sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= s[i] - '0' - 1; j++) {
			ans = (ans + dp[i][(d - sum + d) % d][j]) % mod;
		}
		sum += s[i] - '0';
		sum %= d;
	}
	if (sum == 0) {
		ans = (ans + 1) % mod;
	}
	cout << (ans - 1 + mod) % mod;
	return 0;
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;

#define el				'\n'
#define sz(v)			((int)((v).size()))
#define all(v)          ((v).begin()),((v).end())
#define clr(v, d)		memset(v, d, sizeof(v))

double const EPS = 1e-8, PI = acos(-1);
const int N = 3000 + 9, M = 100 + 9, OO = (int) 1e6 + 1;
const long long MOD = 998244353;

typedef long long ll;

void OUTPUT() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

void INPUT() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}

ll dp[N][N];
int main() {
//	INPUT();
	OUTPUT();
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int L = n - 1; L >= 0; L--) {
		for (int R = L; R < n; R++) {
			if (L == R)
				dp[L][R] = v[L];
			else {
				dp[L][R] = max(v[L] - dp[L + 1][R], v[R] - dp[L][R - 1]);
			}
		}
	}
	cout << dp[0][n - 1];

	return 0;

}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define all(x)              (x).begin(), (x).end()
#define inf                 1e18

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	ll k;
	string s;
	cin >> s >> k;
	int n = s.size();
	vector < vector < vector <ll> > > dp(n + 1, vector < vector <ll> > (k + 100, vector <ll> (2)));
	dp[0][0][1] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int z = 0; z < 2; ++z) {
				for (int d = 0; d <= 9; ++d) {
					if (j + (d != 0) > k) {
						continue;
					}
					if (j > i || (d > s[i] - '0' && z == 1)) {
						continue;
					}
					dp[i + 1][j + (d != 0)][z & (d == s[i] - '0')] += dp[i][j][z];
				}
			}
		}
	}
	cout << dp[n][k][1] + dp[n][k][0];
}
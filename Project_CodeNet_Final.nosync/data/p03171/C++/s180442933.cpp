/* 
chirag11032000
Chirag Thakur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template < typename T > using OrderedSet = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

const db PI = acos(-1);
const ll LINF = LLONG_MAX;
const int INF = INT_MAX, MOD = 1e9 + 7, N = 1e4 + 10;

int a[N];
ll dp[2][N][2];

void test_case();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
	return 0;
}

void test_case() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int l = n; l >= 1; --l) {
		for (int r = 1; r <= n; ++r) {
			for (int take_max = 0; take_max <= 1; ++take_max) {
				int curr = l & 1, nxt = !curr;
				if (l > r) {
					dp[curr][r][take_max] = 0;
				} else if (take_max) {
					dp[curr][r][take_max] = max(a[l] + (l + 1 <= n ? dp[nxt][r][!take_max] : 0), a[r] + dp[curr][r - 1][!take_max]);
				} else {
					dp[curr][r][take_max] = min(-a[l] + (l + 1 <= n ? dp[nxt][r][!take_max] : 0), -a[r] + dp[curr][r - 1][!take_max]);
				}
			}
		}
	}
	cout << dp[1][n][1] << "\n";
}

// ll solve(int l, int r, bool p) {
//     if (l > r) {
//         return 0;
//     }
//     ll &ans = dp[l][r][p];
//     bool &vis = seen[l][r][p];
//     if (!vis) {
//         vis = true;
//         if (p) {
//             ans = min(solve(l + 1, r, !p) - a[l], solve(l, r - 1, !p) - a[r]);
//         } else {
//             ans = max(solve(l + 1, r, !p) + a[l], solve(l, r - 1, !p) + a[r]);
//         }
//     }
//     return ans;
// }
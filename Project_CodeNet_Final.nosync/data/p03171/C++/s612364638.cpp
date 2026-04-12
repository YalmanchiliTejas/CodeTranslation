/*
lakshaygpt28
Lakshay Gupta
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
using vll = vector < ll >;

template < typename T > using OrderedSet = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;


#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif

#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const db PI = acos(-1);
const ll LINF = LLONG_MAX;
const int INF = INT_MAX, MOD = 1e9 + 7, N = 1e4 + 10;

ll a[N];
ll dp[2][N][2];

// ll solve(int i, int j, int turn);

int main() {
    fast_io();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < N; j++) {
    //         dp[i][j][0] = dp[i][j][1] = -1;
    //     }
    // }
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = 0; j < n; j++) {
            if (i > j) {
                continue;
            }
            for (ll turn = 0; turn <= 1; turn++) {
                dp[i % 2][j][turn] = max(a[i] - dp[(i + 1) % 2][j][turn ^ 1], a[j] - dp[i % 2][j - 1][turn ^ 1]);
            }
        }
    }
    // debug(dp[0][n - 1][0]);
    cout << dp[0][n - 1][0] << "\n";
    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < n; j++) {
    //         debug(i, j, dp[i % 2][j][0], dp[i % 2][j][1]);
    //     }
    // }
    return 0;
}

// ll solve(int i, int j, int turn) {
//     auto &ans = dp[i % 2][j][turn];
//     if (ans != -1 ) {
//         return ans;
//     }
//     if (i > j) {
//         ans = 0;
//         return ans;
//     }
//     ans = max(a[i] - solve(i + 1, j, turn ^ 1), a[j] - solve(i, j - 1, turn ^ 1));
//     return ans;
// }

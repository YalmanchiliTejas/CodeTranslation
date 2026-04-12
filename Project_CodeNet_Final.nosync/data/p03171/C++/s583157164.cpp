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
const int INF = INT_MAX, MOD = 1e9 + 7, N = 3e3 + 10;

ll a[N];
ll dp[N][N][2];

ll solve(ll i, ll j, int turn);

int main() {
    fast_io();
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cout << solve(0, n - 1, 0) << "\n";
    return 0;
}

ll solve(ll i, ll j, int turn) {
    auto &ans = dp[i][j][turn];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (i > j) {
        return ans;
    }
    ans = max(a[i] - solve(i + 1, j, turn ^ 1), a[j] - solve(i, j - 1, turn ^ 1));
    return ans;
}

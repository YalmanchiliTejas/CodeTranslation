#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
//#define int long long
#define pb push_back
#define x first
#define ld long double
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) a.begin(),a.end()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}
const int INF = 1e9, MOD = 1e9 + 7; /// think


const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside (int x, int y, int n, int m) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

inline void set_max (int &a, int b) {
    if (a < b) {
        a = b;
    }
}


const int N = 2001;

int dp[3 * N][3 * N] = {}, a[3 * N] = {};

inline int get_label (int i) {
    return i / 3;
}


int nxt[3 * N][N] = {};

main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i <= 3 * n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            nxt[i][j] = -1;
        }
    }
    for (int i = 1; i <= 3 * n; i++) {
        cin >> a[i];
    }
    int k = n, cnt = 3;
    for (int i = 3; i + 2 <= 3 * n; i += 3) {
        if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
            ++ans;
            --k;
        }
        else {
            a[cnt++] = a[i];
            a[cnt++] = a[i + 1];
            a[cnt++] = a[i + 2];
        }
    }
    a[cnt++] = a[3 * n];
    n = k;
    for (int i = 3 * n; i > 0; i--) {
        for (int j = 1; j < N; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        if (i + 1 <= 3 * n) {
            nxt[i][a[i + 1]] = i + 1;
        }
    }
    for (int i = 0; i <= 3 * n; i++) {
        for (int j = 0; j <= 3 * n; j++) {
            dp[i][j] = -1;
        }
    }
    dp[1][2] = 0;
    auto check = [&] (int A, int B, int C) {
        return a[A] == a[B] && a[B] == a[C];
    };

    auto go = [&] (int A, int B, int C, int D, int E) {
        set_max(dp[A][C], dp[A][B] + check(B, D, E));
        set_max(dp[A][D], dp[A][B] + check(B, C, E));
        set_max(dp[A][E], dp[A][B] + check(B, C, D));
        set_max(dp[B][C], dp[A][B] + check(A, D, E));
        set_max(dp[B][D], dp[A][B] + check(A, C, E));
        set_max(dp[B][E], dp[A][B] + check(A, C, D));
        set_max(dp[C][D], dp[A][B] + check(A, B, E));
        set_max(dp[C][E], dp[A][B] + check(A, B, D));
        set_max(dp[D][E], dp[A][B] + check(A, B, C));
    };

    for (int j = 2; j < 3 * n; j++) {
        for (int i = 1; i < j; i++) {
            if (dp[i][j] == -1) continue;
//            cout << i << ' ' << j << '\n';
            int cur = get_label(j), k = j + 1;
            while (cur == get_label(k)) ++k;
            int K = k - 1;
            if (k + 2 <= 3 * n) {
                go(i, j, k, k + 1, k + 2);
            }
            k = nxt[K][a[i]];
            if (k != -1) {
                k = (k / 3) * 3;
                if (k + 2 <= 3 * n) {
                    go(i, j, k, k + 1, k + 2);
                }
            }
            k = nxt[K][a[j]];
            if (k != -1) {
                k = (k / 3) * 3;
                if (k + 2 <= 3 * n) {
                    go(i, j, k, k + 1, k + 2);
                }
            }
        }
    }
    int res = 0;
    for (int j = 2; j < 3 * n; j++) {
        for (int i = 1; i < j; i++) {
//            cout << dp[i][j] << ' ';
            res = max(res, dp[i][j] + check(i, j, 3 * n));
        }
//        cout << '\n';
    }
    cout << ans + res << '\n';
}

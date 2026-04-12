//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree <pair <ll, int>, null_type, less <pair <ll, int> >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define db double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"

#define left fsdsdfoisf
#define sum dpsdfioppsf
#define assign xcvjlkdjfio
#define trie fksdfkjkfnjuiv
#define next sidlfjsfkl
#define merge sdfksdkfsldf

#define int long long

using namespace std;

void dout() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 1e4 + 7, K = 107, MOD = 1e9 + 7;
int n, d, dp[2][K][N];
string num;

int calc(int f, int rem, int len) {
    if (len == n) {
        return rem == 0;
    }
    int & res = dp[f][rem][len];
    if (res != -1) {
        return res;
    }
    res = 0;
    int tmp = num[len] - '0';
    if (f == 0) {
        for (int i = 0; i < 10; i++) {
            res += calc(0, (rem + i) % d, len + 1);
            if (res >= MOD) {
                res -= MOD;
            }
        }
    }   else {
        for (int i = 0; i < tmp; i++) {
            res += calc(0, (rem + i) % d, len + 1);
            if (res >= MOD) {
                res -= MOD;
            }
        }
        res += calc(1, (rem + tmp) % d, len + 1);
        if (res >= MOD) {
            res -= MOD;
        }
    }
    return res;
}

void solve(int tc) {
    // check for (int i = 0; i < n; j++)
    memset(dp, -1, sizeof(dp));
    cin >> num >> d;
    n = sz(num);
    cout << (calc(1, 0, 0) - 1 + MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}

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

const int N = 3007, inf = 1e15;
int n, a[N], dp[N][N];

int calc(int l, int r) {
    if (l > r) {
        return 0;
    }
    int & res = dp[l][r];
    if (res != -1) {
        return res;
    }
    res = -inf;
    res = max(res, a[l] - calc(l + 1, r));
    res = max(res, a[r] - calc(l, r - 1));
    return res;
}

void solve(int tc) {
    // check for (int i = 0; i < n; j++)
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << calc(1, n);
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

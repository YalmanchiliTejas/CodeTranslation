//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second

using namespace std;
using ll = long long;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 10 , inf = 2e9 + 7;
const ll INF = 1e18 , mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    cout << (n >= 30 ? "Yes" : "No");
}
/*
*/
main() {
    ios;
    int tt = 1;
    //cin >> tt;
    while(tt --) {
        solve();
    }
    return 0;
}

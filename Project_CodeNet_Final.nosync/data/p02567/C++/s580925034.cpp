#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <atcoder/all>

#define F first
#define S second
//#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace atcoder;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3000000;
const int K = 100000;
const int mod = 1e9 + 7;
int op(int a, int b){
    return max(a, b);
}
int e(){
    return -1;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    segtree <int, op, e> st(v);
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int x, v;
            cin >> x >> v;
            st.set(x - 1, v);
        } else
        if (t == 2){
            int l, r;
            cin >> l >> r;
            cout << st.prod(l - 1, r) << endl;
        } else
        if (t == 3){
            int x, v;
            cin >> x >> v;
            cout << 1 + st.max_right (x - 1, [&](int y){ return (v > y);}) << endl;
        }
    }
}

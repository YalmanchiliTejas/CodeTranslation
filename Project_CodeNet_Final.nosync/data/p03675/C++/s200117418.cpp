// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define N (ll)(1e6+3)
#define INF (ll)(1e18+3)
#define MOD (ll)(1e9+7)

#define ll long long
#define rep(i,a,n) for(ll i = a; i < n; i++)
#define per(i,a,n) for(ll i = n-1; i >= a; i--)

//using namespace __gnu_pbds;
using namespace std;
 
// typedef
// tree<
//     pair<ll,ll>,
//     null_type,
//     less<pair<ll,ll>>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>
// ordered_set;

ll n, a[N], b[N];
void solve() {
    cin >> n;
    rep(i,0,n) cin >> a[i];
    ll j = n-1;
    rep(i,0,n) {
        b[i] = a[j];
        if ((j&1) == (n&1))
            j += 2;
        else
            j -= 2;
        if (j < 0) {
            j += 1;
            if (j < 0) j += 2;
        }
    }
    rep(i,0,n) {
        cout << b[i] << " ";
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
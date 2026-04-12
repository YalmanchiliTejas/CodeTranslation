// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("Ofast")
// #pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using o_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define sfind(i) find_by_order(i)
// #define ord(i) order_of_key(i)
typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
using cd = complex<double>;
const double pi = acos(-1);
#define mod 1000000007
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define repc(i, a, b, c) for (ll i = a; (c > 0 ? i < b : i > b) and c != 0; i += c)
#define vi vector<int>
#define vl vector<ll>
#define _max(vec) (*max_element(all(vec)))
#define _min(vec) (*min_element(all(vec)))
#define fi first
#define si second
#define pb push_back
#define all(name) name.begin(), name.end()
#define ral(name) name.rbegin(), name.rend()
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod)
#define mod_in(a) power(a, mod - 2)
#define ncr(n, r) (n>=r?((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod):0LL)
#define deb(x) cerr << "[" << #x << " " << x << "]" << endl;
#define endl '\n'  //....????
#define int ll
vector<ll> ft(1, 1LL);


/*======================================================================*/
void solve(){
    int x;
     cin >> x;
     if(x >= 30)cout << "Yes\n";
     else cout << "No\n";
}
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define mod 1000000007
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define repc(i, a, b, c) for (ll i = a; (c > 0 ? i < b : i > b) and c != 0; i += c)
// #define mp make_pair
#define fi first
#define si second
#define pb push_back
#define all(name) name.begin(), name.end()
#define ral(name) name.rbegin(), name.rend()
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod)
#define mod_in(a) power(a, mod - 2)
#define ncr(n, r) (n>=r?((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod):0LL)
#define deb(x) cerr << "[" << #x << " " << x << "]" << endl;
#define endl '\n'
#define int ll
vector<ll> ft(1, 1LL);

/*======================================================================*/
// ll power(ll x, ll y) {
//     ll res = 1;x %= mod;
//     while (y > 0) {
//         if (y & 1)res = (res*x) % mod;
//         y = y>>1;
//         x = (x*x) % mod;
//     }
//     return res%mod;
// }
// bool cmp(pair<int, int> a, pair<int, int> b){
//     return (a.fi+a.si) > (b.fi+b.si);
// }
// void solve(){
//     int n, s = 0;
//     cin >> n;
//     vector<pair<int, int> > v(n) ;
//     rep(i, 0, n)cin >> v[i].fi >> v[i].si, s += v[i].fi;
//     sort(all(v), cmp);
//     rep(i, 0, n){
//         if(v[i].fi+v[i].si <= s){
//             cout << "INDEFINITELY\n";
//             return;
//         }
//         else s -= v[i].fi;
//     }
//     int mi, ans = s;
//     rep(i,0,n){
//         if()
//     }
// }

void solve() {
    int n;
    cin >> n;
    int sum = 0, ans = 0;
    rep(i, 0, n){
        int a;
        cin >> a;
        ans = (ans + (a*sum))%mod;
        sum = (sum+a)%mod;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // fact((2e6+10));
    // //declare  and  global
    int t = 1;
    // cin >> t;
    rep(i, 0, t){
        solve();
    }
}

//gauravsinghh
#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
using bigint = int64_t;

#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define lob lower_bound
#define upb upper_bound
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ins insert
#define mp make_pair
#define w(t) cin >> t;while(t--)
#define bitcount __builtin_popcount
#define endl "\n"
#define sz(s) (int)s.size()
#define mem(n,m) memset(n,m,sizeof(n))
#define deb(x) cout << #x << " = " << x << endl;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define ren(i,n) for(ll i = n-1; i >= 0; i--)
#define all(x) x.begin(),x.end()
#define fo(i, a, b) for(ll i = a; i <= b; i++)
#define ffo(i, a, b) for(ll i = a; i >= b; i--)
#define ffi(i,a,b,c) for(ll i = a ; i <= b ; i += c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int mod = 1000000007;

void io_set() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    ll n, ans = 0;
    cin >> n;
    ll a[n], suff[n];
    rep(i, n)   cin >> a[i], suff[i] = 0;
    ren(i, n - 1) {
        suff[i] = (suff[i] % mod + (suff[i + 1] % mod + a[i + 1] % mod) % mod) % mod;
    }
    //rep(i, n)   cout << suff[i] << " ";
    rep(i, n) {
        ans = (ans % mod + (a[i] % mod * suff[i] % mod) % mod) % mod;
    }
    cout << ans << endl;
}

int main() {
    IOS;
    //io_set();
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
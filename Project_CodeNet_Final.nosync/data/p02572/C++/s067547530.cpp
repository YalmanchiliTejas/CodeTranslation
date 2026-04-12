#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    cin.tie(nullptr) ;
    ios::sync_with_stdio(false) ;

    //ifstream in("/home/spady/Cpp/Practice/tester/debug_out.log");
    //cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) {
        cin >> a[i];
        a[i] %= MOD;
    }
    vector<ll> sum(n + 1, 0);
    repp(i, 1, n + 1) { sum[i] = (sum[i - 1] + a[i-1])%MOD; }
    ll res = 0;
    for (ll i = 0; i < n;i++){
        ll m = (sum[n] - sum[i + 1]);
        if (m < 0) m += MOD;
        res += ((a[i] * m) % MOD) % MOD;
    }
    cout << res%MOD << "\n";
    return 0;
}

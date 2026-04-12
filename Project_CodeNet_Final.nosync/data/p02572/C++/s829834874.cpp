#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using P = pair<int, int>;

constexpr int INF = 1e9;
constexpr ll INFLL = 1e18;
constexpr int MOD = 1e9 + 7;
const ld PI = acosl(-1);

#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(n) n.begin(),n.end()

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //cout << fixed << setprecision(6);
    int n; cin >> n;
    vll a(n);
    vll cum(n+1, 0);
    rep(i, n) {
        cin >> a[i];
        cum[i+1] = cum[i] + a[i];
    }

    ll ans = 0;
    rep (i, n) {
        ans += (a[i] * ((cum[n] - cum[i+1]) % MOD)) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
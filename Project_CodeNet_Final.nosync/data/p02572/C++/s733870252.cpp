#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)
#define revrep(i,n) for(ll i=n-1; n>=0; --i)
inline constexpr ll Inf = (1ULL << 62) -1;

const ll Mod = 1e9+7;
int main() {
    ll ans=0, N;
    cin >> N;
    vector<ll> a(N+1);
    rep1(i,N) cin >> a[i];
    ll s = 0;
    rep1(i,N) {
        ans += a[i]*s;
        ans %= Mod;
        s += a[i];
        s %= Mod;
    }
    cout << ans << endl;
}

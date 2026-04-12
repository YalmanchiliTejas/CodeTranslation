#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)
#define revrep(i,n) for(ll i=n-1; n>=0; --i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <class T>
void updatemax(T& a, T b) { if (b > a) a = b; }

int main() {
    ll ans=0, N;
    ll Mod = 1e9+7;
    cin >> N;
    vector<ll> a(N+1);
    rep1(i,N) cin >> a[i];
    vector<ll> p = a;
    for (int i=N; i > 1; --i) {
        p[i-1] += p[i];
        p[i-1] %= Mod;
    }
    for (int i=1; i<=N-1; ++i) {
        ans += a[i]*p[i+1];
        ans %= Mod;
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)
#define revrep(i,n) for(ll i=n-1; i>=0; --i)
inline constexpr ll Inf = (1ULL << 62) -1;
#define fastio cin.tie(nullptr); ios_base::sync_with_stdio(false);
#define endl '\n'
template <class T> bool updmax(T& a, T b) { if (b > a) { a = b; return true;} return false;}
template <class T> bool updmin(T& a, T b) { if (b < a) { a = b; return true;} return false;}


int main() {
    fastio;
    ll ans=0;
    ll N;
    cin >> N;
    int X, M;
    cin >> X >> M;
    map<int,int> c;
    int x = X;
    int cycle = 0;
    int start = 0;
    rep1(i, M+1) {
        if (c.count(x)) {
            cycle = i-c[x];
            start = c[x];
            break;
        }
        c[x] = i;
        x = (ll)x * x % M;
    }
    int t = X;
    for (int i=1; i <= min(N,(ll)start); ++i) {
        ans += t;
        t = (ll)t*t % M;
    }
    if (N > start) {
        t = x;
        ll cs = 0;
        rep(i, cycle) {
            cs += t;
            t = (ll)t*t % M;
        }
        ans += (N - start)/cycle * cs;

        int r = (N - start) % cycle;
        cs = 0;
        t = (ll)x*x % M;
        for (int i=0; i<r; ++i) {
            cs += t;
            t = (ll)t*t % M;
        }
        ans += cs;
    }
    cout << ans << endl;
}

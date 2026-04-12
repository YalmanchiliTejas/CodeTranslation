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

const int bits = 35;
int table[100005][bits];
ll sum[100005][bits];

int main() {
    fastio;
    ll ans=0;
    ll N;
    int X, M;
    cin >> N >> X >> M;
    rep(x,M) {
        table[x][0] = x * x % M;
        sum[x][0] = x;
    }
    rep(i,bits-1) rep(x,M) {
        table[x][i+1] = table[table[x][i]][i];
        sum[x][i+1] = sum[x][i] + sum[table[x][i]][i];
    }
    int s = X;
    for (int i=0; i<bits; ++i) {
        if (N & (1LL << i)) {
            ans += sum[s][i];
            s = table[s][i];
        }
    }
    cout << ans << endl;
}

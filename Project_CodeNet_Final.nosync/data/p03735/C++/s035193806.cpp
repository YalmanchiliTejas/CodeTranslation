#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using u64 = uint_fast64_t;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return true;} return false; }
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return true;} return false; }
inline int popcount(int x) {return __builtin_popcount(x);}
inline int popcount(long long x) {return __builtin_popcountll(x);}
void print() { cout << "\n"; }
template<class T, class... Args>
void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> x(N),y(N);
    ll xMIN = 1e18, xMAX = 0, yMIN = 1e18, yMAX = 0;
    int numMIN = -1;
    rep(i,N) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) swap(x[i],y[i]);
        if (chmin(xMIN,x[i])) numMIN = i;
        chmax(xMAX,x[i]);
    }
    
    vector<int> idx(N);
    iota(all(idx),0);
    sort(all(idx),[&](int i, int j){return y[i] > y[j];});
    yMAX = y[idx[0]];
    ll XX = 0;
    yMIN = y[idx.back()];
    ll ans = (xMAX-xMIN)*(yMAX-yMIN);
    rep(i,N) {
        int u = idx[i];
        if (u==numMIN) break;
        chmax(XX,x[u]);
        yMAX = max(XX,y[idx[i+1]]);
        chmin(yMIN,x[u]);
        chmax(xMAX,y[u]);
        chmin(ans,(xMAX-xMIN)*(yMAX-yMIN));
    }

    cout << ans << ln;
}
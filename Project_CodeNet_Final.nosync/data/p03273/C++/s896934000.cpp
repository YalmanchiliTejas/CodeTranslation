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
    int H,W; cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];

    vector<bool> R(H),C(W);
    rep(i,H) rep(j,W) {
        if (S[i][j]=='#') R[i] = C[j] = 1;
    }
    rep(i,H) {
        if (!R[i]) continue;
        rep(j,W) if (C[j]) cout << S[i][j];
        cout << ln;
    }
}
#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define BUGAVOID(x) x
#define rep(...) BUGAVOID(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define sz(c) (int)(c.size())
#define all(c) c.begin(),c.end()
#define mp make_pair
#define write(x) cout<<(x)<<"\n"
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vll; template<class T, class U>using vp = vector<pair<T, U>>;
template<class T>using vv = vector<vector<T>>; template<class T, class U>using vvp = vv<pair<T, U>>;
template<class T>vv<T> vvec(size_t n, size_t m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T>bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 28, MAX = 1e5 + 5, MOD = 1e9 + 7;
constexpr ll LINF = 1ll << 60; constexpr double EPS = 1e-6;
constexpr int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); }; }aaaa;

int N;
vi H;

int main() {
    cin >> N;
    H.resize(N);
    rep(i, N) cin >> H[i];

    int M = H[0];
    int cnt = 1;
    rep(i, 1, N) {
        if (H[i] >= M) cnt++;

        M = max(M, H[i]);
    }

    write(cnt);
}
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) for(int i=(n)-1;0<=i;--i)
#define each(e,v) for(auto&& e:(v))
#define all(v) begin(v),end(v)
#define DUMP(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<": "<<(x)<<" (L"<<__LINE__<<")"<<endl
using namespace std;
using vint = vector<int>;
using vdouble = vector<double>;
using vstring = vector<string>;
using ll = long long;
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

constexpr int N = 'z' - 'a' + 1;
constexpr int INF = 1e9;

int main() {
    int n; cin >> n;
    vstring S(n);
    rep(i, n) cin >> S[i];
    vint cnt(N, INF);
    rep(i, n) {
        vint cnt2(N, 0);
        for(char c: S[i]) cnt2[c - 'a']++;
        rep(i, N) chmin(cnt[i], cnt2[i]);
    }
    rep(i, N) rep(j, cnt[i]) cout << (char)('a' + i);
    cout << endl;
    return 0;
}

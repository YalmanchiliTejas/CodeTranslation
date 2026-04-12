#include <bits/stdc++.h>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr int INF = 1001001001;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    
    ll v = x, y;
    vector<bool> b(m, false);
    while (1) {
        if (b[v]) {
            y = v;
            break;
        }
        b[v] = true;
        v = (v*v) % m;
    }
    
    v = x;
    ll d1 = 0, s1 = 0;
    while (1) {
        if (v == y) {
            break;
        }
        d1++;
        s1 += v;
        v = (v*v) % m;
    }
    
    v = y;
    ll d2 = 0, s2 = 0;
    while (1) {
        d2++;
        s2 += v;
        v = (v*v) % m;
        if (v == y) break;
    }
    
    ll d3 = max(0LL, (n - d1) % d2), s3 = 0;
    v = y;
    rep (i, d3) {
        s3 += v;
        v = (v*v) % m;
    }
    //cout << "d:" << d1 << ", " << d2 << ", " << d3 << endl;
    //cout << "s:" << s1 << ", " << s2 << ", " << s3 << endl;
    ll ans = s1 + s2 * max(0LL, (n - d1) / d2) + s3;
    cout << ans << endl;
    
    return 0;
}

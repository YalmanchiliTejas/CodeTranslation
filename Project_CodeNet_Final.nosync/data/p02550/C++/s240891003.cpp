#include <bits/stdc++.h>
using namespace std;
using ll        = long long;
using ld        = long double;
using vl        = vector<ll>;
using vd        = vector<ld>;
using vs        = vector<string>;
using vb        = vector<bool>;
using vvl       = vector<vector<ll>>;
using vvd       = vector<vector<ld>>;
using vvs       = vector<vector<string>>;
using vvb       = vector<vector<bool>>;
using pll       = pair<ll, ll>;
constexpr ll mod= 1e9 + 7;
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for(ll(i)= 0; (i) < (n); (i)++)
#define REPS(i, n) for(ll(i)= 1; (i) <= (n); (i)++)
#define RREP(i, n) for(ll(i)= (n - 1); (i) >= 0; (i)--)
#define RREPS(i, n) for(ll(i)= (n); (i) > 0; (i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
#define YES(n) ((n) ? "YES" : "NO")
#define Yes(n) ((n) ? "Yes" : "No")
#define yes(n) ((n) ? "yes" : "no")

template <class T>
inline void chmin(T& a, T b) {
    if(a > b) { a= b; }
}

template <class T>
inline void chmax(T& a, T b) {
    if(a < b) { a= b; }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ll X, N, M;
    cin >> N >> X >> M;
    ll ans= 0;
    vl EM(M, -1);
    vl lo(M * 2);
    bool did= 0;
    REP(i, N) {
        if(i != 0) {
            if(EM[X] != -1 && did == 0) {
                ll nokori= N - i;
                ans+= (nokori / (i - EM[X])) * (lo[i - 1] - lo[EM[X] - 1]);
                i+= (nokori / (i - EM[X]))*(i - EM[X]);
                did= 1;
            }
        }
        if(i >= N)break;
        ans+= X;
        if(i != 0 && did == 0) EM[X]= i;
        if(did == 0) lo[i]= ans;
        X= X * X % M;
        if(X == 0) break;
    }
    cout << ans << "\n";
}
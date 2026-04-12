#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define ld          long double
#define endl        "\n"

const int mod = 998244353;

inline int add(int a, int b) { int res = a + b; if(res >= mod) res -= mod;  return res; }
inline int sub(int a, int b) { int res = a - b; if(res < 0) res += mod; return res;}
inline int mul(int a, int b) { return (a * b)%mod; }

void solve() {
    int N, S; cin >> N >> S;
    int a[N+1];
    for(int i=1; i<=N; i++) cin >> a[i];
    int d[N+1][3003];    memset(d, 0, sizeof d);
    int pd[N+1][3003];   memset(pd, 0, sizeof pd);
    for(int i=1; i<=N; i++) {
        d[i][a[i]] = i;
        //pd[i][a[i]] = add(pd[i-1][a[i]], d[i]a[i]);
        for(int j=0; j<=S; j++) {
            if(j > a[i]) {
                d[i][j] = add(d[i][j], pd[i-1][j-a[i]]);
            }
            pd[i][j] = add(pd[i-1][j], d[i][j]);
        }
    }
    int ans = 0;
    for(int i=1; i<=N; i++) ans = add(ans, mul(N-i+1, d[i][S]));
    cout << ans << endl;
}


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007
#define INF (1 << 30)
#define REP(i, m, n) for(int i = (int)m; i < (int)n; ++i)
#define rep(i, n) REP(i, 0, n)

vector<ll> len(55), pat(55);

ll rec(ll n, ll x) {
    if(n == 0) return x >= 1;
    if(x == 1) return 0;
    if(1 < x && x <= 1+len[n-1]) return rec(n-1, x-1);
    if(x == 2+len[n-1]) return 1+pat[n-1];
    if(2+len[n-1] < x && x <= 2+2*len[n-1]) return 1+pat[n-1]+rec(n-1, x-2-len[n-1]);
    if(x == 3+2*len[n-1]) return 1+2*pat[n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    len[0] = 1, pat[0] = 1;
    rep(i, n) {
        len[i+1] = 2*len[i] + 3;
        pat[i+1] = 2*pat[i] + 1;
    }
    cout << rec(n, x) << '\n';
    return 0;
}
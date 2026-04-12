#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define DOUBLE(d) cout << fixed << setprecision(15) << (d) << endl

const int MAX = 1e5+10;
const ll INF = 1e18;

int N;
ll S[MAX];

ll solve() {
    ll ret = -INF;
    FOR (c, 1, N) {
        ll f = 0;
        REP (n, N/c) {
            f += S[n*c] + S[N-1-n*c];
            if (n*c == N-1 - n*c || n*c == N-1 - (n-1)*c) f = -INF;
            CHMAX(ret, f);
        }
    }
    return ret;
}

int main() {
    cin >> N;
    REP (i, N) cin >> S[i];
    cout << solve() << endl;
}
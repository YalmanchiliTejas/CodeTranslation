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

const int MAX = 2e5+10;
const ll INF = 1e15;
const int K = 10;
int N;
ll A[MAX];

ll dp[MAX*K][2];

inline int idx(int n, int k) {
    return n * K + k - n/2 + K/2;
}

ll solve() {
    REP (i, MAX) REP (k, K) dp[i*K+k][0] = dp[i*K+k][1] = -INF;
    dp[idx(1, 0)][0] = 0;
    dp[idx(1, 1)][1] = A[0];
    FOR (n, 2, N+1) FOR (k, (n-1)/2-2, (n+1)/2+2) {
        CHMAX(dp[idx(n, k)][0], dp[idx(n-1, k)][0]);
        CHMAX(dp[idx(n, k)][0], dp[idx(n-1, k)][1]);
        CHMAX(dp[idx(n, k)][1], dp[idx(n-1, k-1)][0] + A[n-1]);
    }

    return max(dp[idx(N, N/2)][0], dp[idx(N, N/2)][1]);
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    cout << solve() << endl;
}
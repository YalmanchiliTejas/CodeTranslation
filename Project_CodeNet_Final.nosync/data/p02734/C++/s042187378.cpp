#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
void chmax(T &a, U b) {
    if (a < b) a = b;
}
template <class T, class U>
void chmin(T &a, U b) {
    if (b < a) a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 998244353;
const ll inf = (1LL << 50);

void solve(long long N, long long S, std::vector<long long> A) {
    int ans = 0;
    vi dp(S + 1, 0);
    rep(i, N) {
        dp[0]++;
        vi dp2 = dp;
        rep(jj, S + 1) {
            int j = S - jj;
            if (j - A[i] >= 0) {
                dp2[j] += dp[j - A[i]];
                dp2[j] %= mod;
            }
        }
        dp = dp2;
        ans = (ans + dp[S]) % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    long long N;
    scanf("%lld", &N);
    long long S;
    scanf("%lld", &S);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, S, std::move(A));
    return 0;
}

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

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

void solve(long long N, std::vector<long long> a) {
    vvi dp(N + 1, vi(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        rep(l, N - i + 1) {
            int r = l + i;
            if ((N - i) % 2 == 0) {
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
            } else {
                dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
            }
        }
    }
    cout << dp[0][N] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}

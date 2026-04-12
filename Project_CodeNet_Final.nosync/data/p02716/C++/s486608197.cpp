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

#define rep(i, j, k) for (int i = j; i < k; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr << #x << ": " << x << ", " << #y << ": " << y << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 60);

int dp[200100][5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    vi a(N);
    rep(i, 0, N) cin >> a[i];

    rep(i, 0, N + 100) rep(j, 0, 4) dp[i][j] = -inf;
    dp[0][0] = 0;

    rep(i, 0, N) rep(j, 0, 3) {
        chmax(dp[i + 1][j + 1], dp[i][j]);
        int now = dp[i][j];
        if ((i + j) % 2 == 0) now += a[i];
        chmax(dp[i + 1][j], now);
    }

    cout << dp[N][1 + N % 2] << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll INF = 1e18;
const int mod = 1e9+7;
const int MAX = 1e6;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visit[MAX]; // 訪問の有無

ll power(int m, int n) { // m^n（繰り返し自乗法）
    if (n == 0) return 1;
    if (n % 2 == 1) return power(m, n-1) * m % mod;
    ll r = power(m, n/2);
    return r * r % mod;
}

ll inv(ll a, ll b) { // 逆元を利用してa/bのmodを返す
    return a * power(b, mod-2) % mod;
}

int n; // 変数
int a[MAX];
ll sum = 0;
ll ans = 0;

int main() {
// input
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
// solve
    rep(i, n) {
        ans += (sum - a[i]) % mod * a[i] % mod;
        ans %= mod;
        sum -= a[i];
    }
// output
    cout << ans << "\n";
}
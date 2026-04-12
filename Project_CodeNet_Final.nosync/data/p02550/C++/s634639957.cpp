#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vector<T>>;

constexpr int64_t mpow(int64_t a, int64_t b, int64_t mod = 1000000007) {
    if (b <= 0) { return 1; } if (b == 1) { return a % mod; } if (b == 2) { return (a * a) % mod; }
    return (max(a * (b & 1), (int64_t)1) * mpow(mpow(a, b / 2, mod), 2, mod)) % mod;
}
constexpr int64_t mdiv(int64_t a, int64_t b, int64_t mod = 1000000007) {
    return (a * mpow(b, mod - 2, mod)) % mod;
}

int main() {
    int64_t n, x, m; cin >> n >> x >> m;

    int64_t cbeg, clen;
    vec<int64_t> sum(2);
    sum[0] = 0; sum[1] = x;

    // 剰余の結果は一意なので、高々mでサイクルを見つけることができる
    {
        vec<int> vis(m, -1); vis[x] = 0;
        for (int64_t i = (x * x) % m, j = x; ; j = i, i = (i * i) % m) {
            if (0 <= vis[i]) {
                cbeg = vis[i];
                clen = vis[j] + 1 - vis[i];
                break;
            }
            vis[i] = vis[j] + 1;
            sum.push_back(sum.back() + i);
        }
    }

    int64_t ans = 0;

    // サイクルの手前まで移動
    ans += sum[min(n, cbeg)];
    n -= min(n, cbeg);
    // サイクルを回る
    ans += (n / clen) * (sum[cbeg + clen] - sum[cbeg]);
    n %= clen;
    // 端数を移動
    ans += sum[cbeg + n] - sum[cbeg];

    cout << ans << endl;
}


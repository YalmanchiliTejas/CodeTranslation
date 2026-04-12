#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, X;
// a: 総数
// p: レベル iにあるパティの枚数
vector<ll>a, p;

ll f(ll L, ll X) {
    // cout << L << " " << X << endl;
    if (L == 0) {
        if (X <= 0) return 0;
        return 1;
    }

    ll mid = (a[L] + 1) / 2;

    if (mid < X) {
        // 真ん中より大きい
        return p[L - 1] + 1 + f(L - 1, X - mid);
    } else if (mid == X) {
        // ちょうど真ん中
        return p[L - 1] + 1;
    } else {
        // 真ん中未満
        return f(L - 1, X - 1);
    }
}

int main() {
    cin >> N >> X;
    a.resize(N + 1);
    p.resize(N + 1);

    a[0] = 1;
    p[0] = 1;

    for (int i = 0; i < N;  i++) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }

    ll ans = f(N, X);
    cout << ans << endl;
    // rep(i, N + 1) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // rep(i, N + 1) {
    //     cout << p[i] << " ";
    // }
    // cout << endl;
}
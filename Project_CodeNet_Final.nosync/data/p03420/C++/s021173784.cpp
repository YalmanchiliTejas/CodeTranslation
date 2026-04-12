#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    ans += (N - K + 1) * (N - K) / 2;
    // cout << ans << endl;

    reps(i, K + 1, N + 1) {
        ll cnt = (N - i + 1) / i;
        ll res = (N - i + 1) % i;

        // cout << "i: " << i << ", cnt:" << cnt << ", res: " << res << endl;
        // cout << cnt * (i - K) << ", " << max(0LL, res - K) << endl;

        ans += cnt * (i - K);
        ans += max(0LL, res - K);
    }

    // reps(n, K, N + 1) {
    //     ans += N - n;
    //     reps(i, K + 1, n + 1) {
    //         // cout << "(" << n << "," << i << ")" << endl;
    //         if (n % i >= K) ans++;
    //     }
    // }

    cout << ans << endl;

    return 0;
}
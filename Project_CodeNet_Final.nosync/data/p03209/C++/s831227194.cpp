#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
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
    ll N, X;
    cin >> N >> X;

    ll npow;
    vector<ll> cnt(5, 0);

    ll ans = 0;

    for (ll i = N; i >= 0; i--) {
        // cout << "---" << i << "---" << endl;
        if (X == 0) break;

        if (i == 0) {
            ans += 1;
            break;
        } else if (i == 1) {
            if (X == 2) {
                ans += 1;
            } else if (X == 3) {
                ans += 2;
            } else if (X == 4 || X == 5) {
                ans += 3;
            }
            break;
        }

        npow = 2 * pow(2LL, i - 1);
        cnt[0] = 1;
        cnt[1] = 2 * npow - 2;
        cnt[2] = 2 * npow - 1;
        cnt[3] = 4 * npow - 4;
        cnt[4] = 4 * npow - 3;

        // repv(cnt) cout << *it << " ";
        // cout << endl;

        auto it = upper_bound(ALL(cnt), X);
        ll idx = it - cnt.begin() - 1;
        // cout << X << "-> " << cnt[idx] << ", ";

        if (idx == 1) {
            ans += pow(2LL, i) - 1;
            // cout << "ans += " << pow(2LL, i) - 1 << endl;
        } else if (idx == 2) {
            ans += pow(2LL, i);
            // cout << "ans += " << pow(2LL, i) << endl;
        } else if (idx == 3 || idx == 4) {
            ans += 2 * pow(2LL, i) - 1;
            // cout << "ans += " << 2 * pow(2LL, i) - 1 << endl;
        }

        X -= cnt[idx];
        // cout << X << endl;
        // cout << "ans : " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
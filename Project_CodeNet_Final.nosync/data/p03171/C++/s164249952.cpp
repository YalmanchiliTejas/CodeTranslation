#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#ifdef _DEBUG_
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl
#else
#define dump(val)
#endif

using namespace std;

typedef long long int ll;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> a(N);
    REP(i, 0, N) {
        cin >> a[i];
    }

    const ll inf = 1LL << 60;
    auto dp = make_v(N, N, inf);
    function<ll(int, int, int)> rec = [&](int l, int r, int t) {
        if (l > r) return 0LL;
        if (dp[l][r] != inf) return dp[l][r];
        ll lv = rec(l + 1, r, !t) + (2 * t - 1) * a[l];
        ll rv = rec(l, r - 1, !t) + (2 * t - 1) * a[r];
        ll res = (t ? max(lv, rv) : min(lv, rv));
        return dp[l][r] = res;
    };

    cout << rec(0, N - 1, 1) << endl;

    return 0;
}

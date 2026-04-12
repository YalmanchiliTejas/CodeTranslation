#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"
#include "profile.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define profile(X) LOG_DURATION(X)
#else
#define debug(...) 42
#define profile(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 600001;
const ll MOD = 1e9 + 7;
using cd = complex<double>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

struct basis {
    ll pivot[60];
    bool empty = false;

    void add(ll val) {
        for (int i = 0; i < 60; ++i) {
            if (val & (1ll << i)) {
                val ^= (pivot[i]);
            }
        }
        for (int i = 0; i < 60; ++i) {
            if (val & (1ll << i)) {
                pivot[i] = val;
                for (int e = 0; e < 60; ++e) {
                    if (e == i) {
                        continue;
                    }
                    if (pivot[e] & (1ll << i)) {
                        pivot[e] ^= pivot[i];
                    }
                }
                break;
            }
        }
    }

    bool has(ll val) {
        for (int i = 0; i < 60; ++i) {
            if (val & (1ll << i)) {
                val ^= pivot[i];
            }
        }
        return val == 0;
    }
};


signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif

    auto solve = [&](int _) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        int mn = 1e9;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
            if (v[i].first > v[i].second) {
                swap(v[i].first, v[i].second);
            }
            mx = max(mx, v[i].second);
            mn = min(mn, v[i].first);
        }
        ll ans = 1e18;
        sort(v.begin(), v.end());
        multiset<ll> blue_ends;
        ll width_red = mx - mn;
        for (int i = 0; i < n; ++i) {
            blue_ends.insert(v[i].first);
        }
        int j = 0;
        vector<pair<int, int>> cock;
        for (int i = 0; i < n; ++i) {
            cock.push_back({v[i].first, i});
            cock.push_back({v[i].second, i});
        }
        sort(cock.begin(), cock.end());
        int up_bound = 1e9;
        for (int i = 0; i < n; ++i) {
            up_bound = min(up_bound, v[i].second);
        }
        for (int i = 0; i < cock.size(); ++i) {
            int blue_mn = cock[i].first;
            if (blue_mn > up_bound) {
                break;
            }

            while (j < cock.size() && cock[j].first < blue_mn) {
                int ind = cock[j].second;
                blue_ends.erase(blue_ends.find(v[ind].first));
                blue_ends.insert(v[ind].second);
                ++j;
            }
            ans = min(ans, width_red * (*blue_ends.rbegin() - blue_mn));
            debug(ans);
        }
        ll red_mx = 0;
        ll red_mn = 1e9;
        ll blue_mx = 0;
        ll blue_mn = 1e9;
        for (int i = 0; i < n; ++i) {
            blue_mn = min<ll>(blue_mn, v[i].first);
            blue_mx = max<ll>(blue_mx, v[i].first);
            red_mx = max<ll>(red_mx, v[i].second);
            red_mn = min<ll>(red_mn, v[i].second);
        }
        ans = min(ans, (red_mx - red_mn) * (blue_mx - blue_mn));
        cout << ans;
    };

    fast_io();
    cout.precision(9);
    cout << fixed;
    auto start = chrono::steady_clock::now();

    for (int i = 1; i <= 1; ++i) solve(i);
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

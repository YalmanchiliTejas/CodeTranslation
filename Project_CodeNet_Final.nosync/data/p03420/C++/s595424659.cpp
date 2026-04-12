// УЛЬЯНА САМАЯ ЛУЧШАЯ В МИРЕ!!!!!!!!!!!!!

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using std::sort;
using std::reverse;

using ll = long long;

#define forn(i, n) for (ll i = 0; i < (ll) n; ++i)
#define sz(a) static_cast<int>(a.size())
#define endl '\n'

struct __init {
    __init() {
        cin.tie(nullptr);
        std::iostream::sync_with_stdio(false);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
        std::mt19937 rand(300);
    }

    ~__init() {
        #ifdef SEREZHKA
            cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
        #endif
    }
} init;

const ll inf = (ll) 1e9 + 7ll;
const int maxn = (int) 1e6 + 17;

int n, k;

bool read() {
    if (!(cin >> n >> k))
        return false;

    return true;
}

void solve() {
    ll ans = 0;

    for (int a = 1; a <= n; ++a) {
        int t = n - n % a;
        ans += max(0, min(a, k) * (t / a) - 1);
        ans += min(n - t + 1, k);
    }

    cout << 1ll * n * n - ans << endl;
}

int main() {
#if SEREZHKA
    freopen("file.in", "r", stdin);
#endif

    while (read())
        solve();

    return 0;
}

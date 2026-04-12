#include <bits/stdc++.h>

using namespace std;
#define int long long
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *x) -> decltype(cerr << *x, 0);

sim> char dud(...);

struct debug {
#ifndef LOCAL

    ~debug() {
        cerr << endl;
    }

    eni(!=) cerr << boolalpha << i;
        ris;
    }

    eni(==) ris << range(begin(i), end(i));
    }

    sim, class b dor(pair<b, c> d) {
        ris << "(" << d.first << ", " << d.second << ")";
    }

    sim dor(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        ris << "]";
    }

#else
    sim dor(const c &)
    {
        ris;
    }
#endif
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define int long long

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int x = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ans = (ans % mod + (v[i] % mod * x % mod) % mod) % mod;
        x = (x % mod + v[i] % mod) % mod;
    }
    cout << ans << "\n";
}
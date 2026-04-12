#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
void err() { cerr << '\n'; }
template <class T, class ...A>
void err(T a, A ...b) {
    cerr << " " << a; err(b...);
}
#define dbg(a...) cerr << __LINE__ << " [" << #a << "]:", err(a)
#else
#define dbg(a...) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
using vll = vector<long>;
using vi = vector<int>;

int constexpr MOD = (int) 1e9 + 7;

inline void norm(long &a) {
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    vll a(n); for (auto &i : a) cin >> i;
    vll suff(n);
    suff[n - 1] = a[n - 1] % MOD;
    for (int i = n - 2; i >= 0; --i) {
        norm(suff[i] = suff[i + 1] + (a[i] % MOD));
    }
    long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        norm(ans += (suff[i + 1] * a[i]) % MOD);
    }
    cout << ans;
    return 0;
}


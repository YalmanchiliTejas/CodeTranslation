#include <bits/stdc++.h>


using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,n) for (int i = 1; i <= (int)(n); ++i)
#define repd(i,n) for (int i = (int)(n - 1); i >= 0; --i)
#define repds(i,n) for(int i = (int)(n); i > 0; --i)
#define all(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rall(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)
#define sz(a) int((a).size())
using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
template<typename A, size_t N, typename T>
void fillArray(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}

int n;
ll a[100005];
void solve() {
    cin >> n;

    rep(i, n)
        cin >> a[i];

    ll ans = 0;
    for (int c = 1; c < n; ++c) {
        ll res = 0;
        vector<bool> used(n, false);
        for (int x = 0; x * c < n; ++x) {
            auto aa = n - 1 - x * c;
            auto b = aa - c;
            if (b <= 0 || x * c == n - 1 - x * c || used[x * c] || used[n - 1 - x * c])
                break;

            res += a[x * c] + a[n - 1 - x * c];
            used[x * c] = used[n - 1 - x * c] = true;
            ans = max(ans, res);

        }
    }

    cout << ans << endl;

    return;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    solve();

    return 0;
}

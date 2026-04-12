#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

struct COM {
    vector<ll> inv, fac, finv;
    COM(int N) : inv(N), fac(N), finv(N) {
        inv[1] = 1;
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        for (int i = 2; i < N; ++i) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
            fac[i] = fac[i - 1] * i % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    ll calc(int a, int b) {
        return (fac[a] * finv[b] % MOD) * finv[a - b] % MOD;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    auto func = [&]() -> ll {
        ll res = 0;
        for (int i = 1; i < M; ++i)
            (res += (ll)i * (M - i)) %= MOD;
        (res *= (ll)N * N) %= MOD;
        return res;
    };

    ans += func();
    swap(N, M);
    ans += func();

    COM com(N * M);
    (ans *= com.calc(N * M - 2, K - 2)) %= MOD;

    cout << ans << endl;
    return 0;
}

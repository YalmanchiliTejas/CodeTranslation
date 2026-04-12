#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; ++i) {
        ll A;
        cin >> A;
        (sum1 += A) %= MOD;
        (sum2 += A * A) %= MOD;
    }

    ll ans = sum1 * sum1 % MOD;
    ans -= sum2;
    ans *= 500000004;
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;

    return 0;
}

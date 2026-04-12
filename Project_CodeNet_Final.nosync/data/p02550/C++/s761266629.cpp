#include <bits/stdc++.h>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

int main() {
    lint n, x, m;
    scanf("%lld%lld%lld", &n, &x, &m);
    vector<lint> sum = {0};
    lint bf_num = 0, bf_sum = 0;
    {
        lint tmp = x;
        set<lint> S;
        while (S.find(tmp) == S.end()) {
            S.insert(tmp);
            (tmp *= tmp) %= m;
        }
        lint cycle_start = tmp;

        tmp = x;
        while (tmp != cycle_start) {
            ++bf_num;
            bf_sum += tmp;
            (tmp *= tmp) %= m;
        }
        S.clear();
        while (S.find(tmp) == S.end()) {
            S.insert(tmp);
            sum.push_back(tmp);
            (tmp *= tmp) %= m;
        }
        partial_sum(sum.begin(), sum.end(), sum.begin());
    }
    int K = sum.size() - 1;
    if (n <= bf_num) {
        lint tmp = x, ans = 0;
        rep(_, n) {
            ans += tmp;
            (tmp *= tmp) %= m;
        }
        printf("%lld\n", ans);
    } else {
        lint ans = bf_sum;
        n -= bf_num;
        ans += sum[K] * (n / K);
        ans += sum[n % K];
        printf("%lld\n", ans);
    }
}
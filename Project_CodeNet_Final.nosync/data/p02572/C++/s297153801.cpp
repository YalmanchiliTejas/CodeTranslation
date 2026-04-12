#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (llong (Itr) = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

#include <iostream>
#include <vector>
using namespace std;
using llong = long long;

llong n;
vector<llong> a;

int main() {
    cin >> n;
    a.resize(n);
    for (auto &vs:a) cin >> vs;

    a.push_back(0);
    for (int i = a.size() - 1; i > 0; i--) {
        a[i - 1] += a[i];
    }

    llong mod = (llong)1e9 + 7;
    llong ans = 0;
    for (int i = 0; i < n; i++) {
        llong s = (a[i + 1] - a[n]) % mod;
        llong v = a[i] - a[i + 1];
        ans += v * s % mod;
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
};

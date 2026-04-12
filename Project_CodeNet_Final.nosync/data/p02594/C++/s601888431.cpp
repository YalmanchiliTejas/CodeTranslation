#include <bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE

#define V vector
#define P pair

using LL = long long;
#define FOR(i, x, y) \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifndef ONLINE_JUDGE
#define dbg(x...)                             \
    do {                                      \
        cerr << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() { cerr << "\033[39;0m" << endl; }
template <template <typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
    for (auto v : a) cerr << v << ' ';
    err(x...);
}
template <typename T, typename... A>
void err(T a, A... x) {
    cerr << a << ' ';
    err(x...);
}
#else
#define dbg(...)
#endif
#define sz(x) (int)x.size()

LL bin(LL a, LL b, LL p) {
    LL res = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) res = res * a % p;

    return res;
}



void solve() {
    int x;
    scanf("%d", &x);
    if (x >= 30) {
        puts("Yes");
    } else {
        puts("No");
    }
}

int main() {

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}
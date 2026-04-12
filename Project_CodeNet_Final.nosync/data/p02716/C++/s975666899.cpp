#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// #define zerol

#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif


const LL MOD = 1e9+7;

const int N = 2e5+50;

int a[N];
int n, m;
const LL INF = 1e18, INF2 = 2e14;

LL b[2][N];
map<int, LL> mp;

LL solve(int n) {
    if (mp.count(n))
        return mp[n];
    if (n == 1) {
        return max(0, a[1]);
    } else if (n == 0)
        return 0;
    if (n % 2)
        return mp[n] = max(solve(n-1), solve(n-2) + a[n]);
    else
        return mp[n] = max(solve(n-2) + a[n], b[1][n-1]);
}
int main() {
    scanf("%d", &n);
    m = n / 2;
    for (int i=1; i<=n; ++i) 
        scanf("%d", &a[i]);

    for (int i=1; i<=n; ++i) {
        b[i%2][i] = a[i];
    }

    for (int i=1; i<=n; ++i) {
        b[0][i] += b[0][i-1];
        b[1][i] += b[1][i-1];
        dbg(i, b[0][i], b[1][i]);
    }
    cout << solve(n) << endl;
    return 0;
}
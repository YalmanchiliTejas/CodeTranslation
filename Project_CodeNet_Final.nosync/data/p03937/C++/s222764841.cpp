#include <bits/stdc++.h>
using namespace std;
using LL = long long;
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
// -----------------------------------------------------------------------------

const int N = 20;
char s[N][N];

bool solve(int w, int h) {
    int x = 0, y = 0;
    if (s[x][y] != '#') return false;
    while (x != h - 1 || y != w - 1) {
        s[x][y] = '.';
        if (x < h - 1 && s[x + 1][y] == '#') x++;
        else if (y < w - 1 && s[x][y + 1] == '#') y++;
        else return false;
    }
    s[x][y] = '.';
    FOR (i, 0, h) FOR (j, 0, w) if (s[i][j] != '.') return false;
    return true;
}

int main() {
    int w, h; cin >> h >> w;
    FOR (i, 0, h) scanf("%s", s[i]);
    puts(solve(w, h) ? "Possible" : "Impossible");
}
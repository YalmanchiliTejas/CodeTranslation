#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>
#include <queue>
#include <deque>
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ld pi = 3.14159265358979323846264;
const char el = '\n';
//const int inf = 1000'000'000;
 
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
 
template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream &out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream &out = cout) { output(all(x), p, out); }
 
mt19937 rnd(time(NULL));

#define int long long

const int N = 1000 * 10000 + 228;
const int MOD = 998244353;

int n;
int f[N], rf[N];

int mod(int x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

int fp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mod(res * a);
        }
        a = mod(a * a);
        b >>= 1;
    }
    return res;
}

int C(int n, int k) {
    return mod(f[n] * mod(rf[k] * rf[n - k]));
}

int base[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = mod(f[i - 1] * i);
    }
    rf[n] = fp(f[n], MOD - 2);
    for (int i = n - 1; i + 1; --i) {
        rf[i] = mod(rf[i + 1] * (i + 1));
    }
    base[0] = 1;
    for (int i = 1; i <= n; ++i) {
        base[i] = mod(base[i - 1] * 2);
    }
    int res = fp(3, n);
    for (int A = n / 2 + 1; A <= n; ++A) {
        res = mod(res - mod(2 * C(n, A) * base[n - A]));
    }
    cout << res << '\n';
    return 0;
}
/*
<>>><<><<<<<>>><
0 3 2 1 0 1 2 0 1 2 3 4 5 2 1 0 1
0 3 2 1 0 1 2 0 1 2 3 4 5 3 2 0 1 

*/
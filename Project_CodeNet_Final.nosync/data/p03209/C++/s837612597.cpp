#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

// Liバーガー長さ そのうちパティの数
ll a[51], b[51];

ll foo(int n, ll x) {
    if (n == 0) return x;
    ll t = a[n], s = (t - 3) / 2;
    if (x <= 1) return 0;
    if (x >= t - 1) return b[n];
    if (x == s + 1) return b[n - 1];
    if (x == s + 2) return b[n - 1] + 1;
    if (x <= s + 1) return foo(n - 1, x - 1);
    if (x > s + 2) return b[n - 1] + 1 + foo(n - 1, x - (s + 2));
    throw;
}

int main() {
    int n;
    cin >> n;

    ll x;
    cin >> x;

    a[0] = 1;
    b[0] = 1;
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] * 2 + 3;
        b[i + 1] = b[i] * 2 + 1;
    }

    cout << foo(n, x) << endl;

    return 0;
}
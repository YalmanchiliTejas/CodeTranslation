#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    ll x;
    cin >> x;

    ll a = 1, b = 1;
    for (int i = 0; i < n; i++) {
        a = a * 2 + 3;
        b = b * 2 + 1;
    }

    ll r = 0;
    for (int i = n; i > 0; i--) {
        a = (a - 3) / 2;
        b = (b - 1) / 2;
        if (x < 1) break;
        x--;
        if (x < a) continue;
        r += b;
        x -= a;
        if (x < 1) break;
        r++;
        x--;
        if (x < a) continue;
        r += b;
        x -= a;
        if (x < 1) break;
        x--;
        if (x == 0 && i == n) break; else throw;
    }

    cout << r << endl;

    return 0;
}
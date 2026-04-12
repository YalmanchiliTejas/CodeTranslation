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
    ll n;
    cin >> n;

    int x, m;
    cin >> x >> m;

    if (n < 1000000) {
        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += x;
            x = (ll)x * x % m;
        }
        cout << s << endl;
        exit(0);
    }

    vector<int> a(m), b(m, -1);
    int i1 = -1, i2 = -1;
    for (int i = 0;; i++) {
        if (b[x] < 0) {
            a[i] = x;
            b[x] = i;
            x = (ll)x * x % m;
        } else {
            i1 = i;
            i2 = b[x];
            break;
        }
    }

    ll s = 0;
    for (int i = i2; i < i1; i++) {
        s += a[i];
    }
    int l = i1 - i2;
    n -= i2;
    ll k = n / l;
    s *= k;
    for (int i = i2; i < i2 + (int)(n - k * l); i++) {
        s += a[i];
    }
    for (int i = 0; i < i2; i++) {
        s += a[i];
    }

    cout << s << endl;

    return 0;
}
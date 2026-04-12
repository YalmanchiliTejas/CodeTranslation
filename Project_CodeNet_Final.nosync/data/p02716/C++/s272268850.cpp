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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 0) {
        ll r = 0, s = 0;

        for (int i = 0; i < n; i += 2) {
            s += a[i];
            r += a[i + 1];
            r = max(r, s);
        }
        cout << r << endl;

    } else {
        ll r = 0, s = 0, t = 0;

        for (int i = 2; i < n; i += 2) {
            t += a[i];
        }
        ll u = t;

        for (int i = 2; i < n; i += 2) {
            t -= a[i];
            s += a[i - 2];
            r += a[i - 1];
            r = max(r, s);
            u = max(u, r + t);
        }
        cout << u << endl;
    }

    return 0;
}
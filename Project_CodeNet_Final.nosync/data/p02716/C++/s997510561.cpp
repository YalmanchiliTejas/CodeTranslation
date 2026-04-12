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

    int a0, a1;
    cin >> a0 >> a1;

    ll r0 = 0, r1 = max(a0, a1), r2;
    ll s = a0;

    for (int i = 2; i < n; i++) {
        int a;
        cin >> a;

        if (i & 1) {
            r2 = max(r0 + a, s);
        } else {
            r2 = max(r0 + a, r1);
            s += a;
        }
        r0 = r1;
        r1 = r2;
    }

    cout << r1 << endl;

    return 0;
}
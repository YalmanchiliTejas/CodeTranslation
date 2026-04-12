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

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    ll r = 0;
    int m = n - 1;
    for (int d = 1; d < m; d++) {
        ll t = 0;
        for (int i = d; i < m - d; i += d) {
            if (m % d == 0 && i >= m - i) break;
            t += s[i] + s[m - i];
            r = max(r, t);
        }
    }

    cout << r << endl;

    return 0;
}
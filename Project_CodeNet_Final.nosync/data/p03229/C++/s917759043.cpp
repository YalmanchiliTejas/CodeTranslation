#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define ALL(v) (v).begin(), (v).end()
#define PUTS(x) cout << (x) << endl;
vector<Int> IntsIn(int n) {
    auto v = vector<Int>(0);
    for (int i = 0; i < n; i++) {
        Int a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}

int main() {
    Int n;
    cin >> n;
    auto v = IntsIn(n);
    sort(ALL(v), greater<Int>());
    if (n % 2 == 0) {
        auto m = n / 2;
        Int s = 0;
        rep(i, m) {
            if (i < m - 1) {
                s += 2 * v[i];
            } else {
                s += v[i];
            }
        }
        Int t = 0;
        for (int i = m; i < n; i++) {
            if (i == m) {
                t += v[i];
            } else {
                t += 2 * v[i];
            }
        }
        PUTS(s - t);
    } else {
        auto m = n / 2;
        Int s = 0;
        rep(i, m + 1) {
            if (i < m - 1) {
                s += 2 * v[i];
            } else {
                s += v[i];
            }
        }
        Int t = 0;
        for (int i = m + 1; i < n; i++) {
            t += 2 * v[i];
        }

        Int u = 0;
        rep(i, m) {
            u += 2 * v[i];
        }
        Int w = 0;
        for (int i = m; i < n; i++) {
            if (i > m + 1) {
                w += 2 * v[i];
            } else {
                w += v[i];
            }
        }

        PUTS(max(s - t, u - w));
    }
}
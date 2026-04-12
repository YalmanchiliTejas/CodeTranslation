#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define rep(i, a, b) for(int i = a; i < b; ++i)

int debug = 0;

const int N = 5e5;
int p[N], n, x, m, a, i, ind, lencyc, cycle, ans;

main() {
    cin >> n >> x >> m;
    a = x;
    for (i = 1; p[a] == 0; ++i) {
        p[a] = i;
        a = a * a % m;
    }
    ind = p[a];
    lencyc = i - ind;
    if (n <= ind) {
        a = x;
        rep(i, 0, n) {
            ans += a;
            a = a * a % m;
        }
    } else {
        n -= ind;
        a = x;
        rep(i, 1, ind + 1) {
            ans += a;
            a = a * a % m;
        }
        cycle = 0;
        rep(i, ind + 1, ind + lencyc + 1) {
            cycle += a;
            a = a * a % m;
        }
        ans += cycle * (n / lencyc);
        n %= lencyc;
        rep(i, 0, n) {
            ans += a;
            a = a * a % m;
        }
    }
    cout << ans << endl;
}
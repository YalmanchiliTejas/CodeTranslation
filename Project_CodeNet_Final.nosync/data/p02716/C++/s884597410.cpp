#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

vector<int> a;
vector<ll> s, r;
constexpr ll NA = 1LL << 60;

ll solve(int n) {
    if (n == 1) return 0;
    if (n == 2) return max(a[0], a[1]);
    if (r[n] != NA) return r[n];

    ll t = solve(n - 2) + a[n - 1];
    if (n % 2 == 0) {
        t = max(t, s[n]);
    } else {
        t = max(t, solve(n - 1));
    }
    return r[n] = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s.assign(n + 2, 0);
    for (int i = 0; i < n; i += 2) {
        s[i + 2] = s[i] + a[i];
    }

    r.assign(n + 1, NA);

    cout << solve(n) << endl;

    return 0;
}
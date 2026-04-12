#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

long long f(long long n, long long x, vll a, vll p) {
    if (n == 0) {
        return x <= 0 ? 0 : 1;
    } else if (x <= 1 + a[n - 1]) {
        return f(n - 1, x - 1, a, p);
    } else {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1], a, p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int n, x;
    cin >> n >> x;

    vector<long long> a(n + 1, 0), p(n + 1, 0);
    a[0] = 1;
    p[0] = 1;

    for (int i = 1; i <= n; i++) {
        a[i] = 2 * a[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }

    cout << f(n, x, a, p) << endl;
}
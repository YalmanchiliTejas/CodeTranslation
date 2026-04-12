#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


ll all(int n) {
    int i;
    ll res = 1;
    for (i = 0; i <= n; i++) {
        res *= 2;
    }
    return res - 1;
}

ll solve(int n, ll x, ll b) {
    ll nb = (b + 3) / 2 - 3;
    if (n == 0) return 1;
    if (x <= 1) return 0;
    if (x < nb + 1) {
        return solve(n - 1, x - 1, nb);
    }
    if (x == nb + 1) {
        return all(n - 1);
    }
    if (x == nb + 2) {
        return all(n - 1) + 1;
    }
    return all(n - 1) + 1 + solve(n - 1, x - nb - 2, nb);
}

int main(void) {
    int n;
    ll x, b;

    cin >> n >> x;

    b = 1;
    for (int i = 0; i < n + 2; i++) {
        b *= 2;
    }

    cout << solve(n, x, b - 3) << endl;

    return 0;
}
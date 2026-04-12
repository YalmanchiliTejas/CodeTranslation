#include <iostream>
using namespace std;

typedef long long ll;

ll solve(ll total[], ll patty[], ll n, ll x) {
    ll half = (total[n] >> 1);
    if (n == 0) {
        if (x <= 0)
            return 0;
        return 1;
    }
    if (x <= half)
        return solve(total, patty, n - 1, x - 1);
    if (x == half + 1)
        return 1 + solve(total, patty, n - 1, x - 2);
    return patty[n - 1] + 1 + solve(total, patty, n - 1, x - half - 1);
}

int main() {
    ll n, x;
    cin >> n >> x;
    ll total[n + 1], patty[n + 1];
    total[0] = 1;
    patty[0] = 1;
    for (int i = 1; i <= n; i++) {
        total[i] = (total[i - 1] << 1) + 3;
        patty[i] = (patty[i - 1] << 1) + 1;
    }
    cout << solve(total, patty, n, x) << endl;
    return 0;
}

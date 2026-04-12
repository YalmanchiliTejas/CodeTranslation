#include <bits/stdc++.h>

using namespace std;

using ll = long long;

array<ll, 51> num, pate;

ll Level(ll n, ll x) {
    if (n == 0) return 1;
    else if (x == num[n]) return pate[n];
    else if (x == 1) return 0;
    else if (x < 1 + num[n - 1]) return Level(n - 1, x - 1);
    else if (x == 1 + num[n - 1]) return pate[n - 1];
    else if (x == 2 + num[n - 1]) return pate[n - 1] + 1;
    else return pate[n - 1] + 1 + Level(n - 1, x - num[n - 1] - 2);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    num[0] = pate[0] = 1;
    for (int i = 1; i <= n; ++i) {
        num[i] = 3 + 2 * num[i - 1];
        pate[i] = 1 + 2 * pate[i - 1];
    }

    cout << Level(n, x) << endl;

    return 0;
}

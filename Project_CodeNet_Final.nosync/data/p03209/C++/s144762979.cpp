#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll l[60];
ll p[60];

//レベルnのx層のパティの枚数を返す
ll rec(ll n, ll x) {
    if (n == 0) {
        return 1;
    }

    if (x == 1) {
        return 0;
    }

    if (l[n] / 2 + 1 < x) {
        return 1 + p[n - 1] + rec(n - 1, x - (l[n] / 2 + 1));
    } else if (l[n] / 2 + 1 == x) {
        return 1 + p[n - 1];
    } else {
        return rec(n - 1, x - 1);
    }
}

int main() {

    ll n, x; cin >> n >> x;

    l[0] = 1;
    p[0] = 1;

    for (ll i = 1; i <= 50; ++i) {
        l[i] = 2 * l[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    cout << rec(n, x) << endl;
}
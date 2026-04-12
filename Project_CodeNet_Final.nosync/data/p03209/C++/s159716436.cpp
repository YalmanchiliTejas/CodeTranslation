#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, p;

// レベルnバーガーの下からx段までに含まれるパティの数
ll func(ll n, ll x) {
    if (n == 0) {
        return 1;
    }
    if (x == 1) {
        return 0;
    }
    else if (x < 2 + a[n - 1]) {
        return func(n - 1, x - 1);
    }
    else if (x == 2 + a[n - 1]) {
        return p[n - 1] + 1;
    }
    else if (x < 3 + 2 * a[n - 1]) {
        return p[n - 1] + 1 + func(n - 1, x - 2 - a[n - 1]);
    }
    else {
        return 1 + 2 * p[n - 1];
    }
}

int main() {

    ll n, x; cin >> n >> x;
    a.resize(n + 1);
    p.resize(n + 1);
    a[0] = 1;
    p[0] = 1;
    for (ll i = 1; i < n + 1; i++) {
        a[i] = 2 * a[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }
    cout << func(n, x) << endl;
    return 0;
}
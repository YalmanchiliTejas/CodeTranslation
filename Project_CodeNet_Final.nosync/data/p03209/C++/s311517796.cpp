#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

vector<ll> a(51, 1);
vector<ll> p(51, 1);

ll f(ll n, ll x) {
    if (n == 0) {
        return x > 0 ? 1 : 0;
    }
    if (x <= a[n - 1] + 1) {
        return f(n - 1, x - 1);
    } else {
        // + 1 is center patty / -2 are first buns & center patty
        return p[n - 1] + 1 + f(n - 1, x - a[n - 1] - 2);
    }
}

int main() {
    ll n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
        //cout << i << ": " << a[i] << "/" << p[i] << endl;
    }

    cout << f(n, x) << endl;
}

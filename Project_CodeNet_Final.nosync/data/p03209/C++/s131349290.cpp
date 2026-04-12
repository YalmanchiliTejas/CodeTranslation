#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
using ll = long long;

ll a(ll n) {
    if (n == 0) return 1;
    return 2 * a(n-1) + 3;
}

ll p(ll n) {
    if (n == 0) return 1;
    return 2 * p(n-1) + 1;
}

ll f(ll n, ll x) {
    if (n == 0 && x == 1) return 1;
    else if (n == 0 && x == 0) return 0;
    else if (x == 0) return 0;
    else if (x == 1) return 0;
    else if (2 <= x && x <= 1+a(n-1)) {
        return f(n-1, x-1);
    }
    else if (x == 2+a(n-1)) return p(n-1) + 1;
    else if (3+a(n-1) <= x && x <= 2+2*a(n-1)) {
        return p(n-1) + 1 + f(n-1, x-2-a(n-1));
    }
    else if (x == 3+2*a(n-1)) {
        return 2*p(n-1) + 1;
    }
    return 0;
}

int main() {
    ll n, x;
    cin >> n >> x;
    cout << f(n, x) << endl;
    return 0;
}
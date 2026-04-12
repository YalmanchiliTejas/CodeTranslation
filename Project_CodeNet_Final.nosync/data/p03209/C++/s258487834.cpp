#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll a(int i) {
    if(i == 0) {
        return 1;
    }

    return 2*a(i-1) + 3;
}

ll p(int i) {
    if(i == 0) {
        return 1;
    }

    return 2*p(i-1) + 1;
}

ll f(int n, ll x) {
    if(n == 0) {
        return 1;
    }
    if(x == 1) {
        return 0;
    }
    else if(x <= a(n-1) + 1) {
        return f(n-1, x-1);
    }
    else if(x == a(n-1) + 2) {
        return p(n-1) + 1;
    }
    else if(x <= 2*a(n-1) + 2) {
        return p(n-1) + 1 + f(n-1, x - 2 - a(n-1));
    }
    else if(x == a(n)) {
        return p(n);
    }
}

int main() {
    int n;
    ll x;
    cin >> n >> x;

    cout << f(n, x) << endl;
    return 0;
}
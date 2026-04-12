#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

ll powmod(ll a, ll b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = int(res * 1ll * a % mod), --b;
        } else {
            a = int(a * 1ll * a % mod), b >>= 1;
        }
    }
    return res;
}

ll reverse(ll a) {
    return powmod(a, mod - 2);
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
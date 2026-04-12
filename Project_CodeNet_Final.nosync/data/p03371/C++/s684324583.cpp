#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll m = 999999999999;
    for (int i = 0; i <= X; i++) {
        if (i* A > m) { break; }
        ll k = (X - i) * 2;
        ll j;
        if (B < 2 * C) {
            // buy B
            j = max(ll(0), Y - (X - i));
        } else {
            k = max(k, Y*2);
        }
        ll cost = i * A + j * B + k * C;
        m = min(m, cost);
    }

    cout << m << endl;
}

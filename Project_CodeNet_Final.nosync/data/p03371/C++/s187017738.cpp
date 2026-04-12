#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll m = 999999999999;
    for (int c = 0;; c += 2) {
        int a = max(0, X - c / 2);
        int b = max(0, Y - c / 2);
        ll cost = a * A + b * B + c * C;
        m = min(m, cost);
        if (a == 0 && b == 0) { break; }
    }

    cout << m << endl;
}

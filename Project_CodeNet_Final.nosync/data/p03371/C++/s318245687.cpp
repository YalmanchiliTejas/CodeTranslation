#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >>Y;

    int ans = 5000 * 2 * 1E+5;
    for (int c=0; c<=max(X, Y) * 2; c+=2) {
        int a = max(X - c / 2, 0);
        int b = max(Y - c / 2, 0);
        int cost = a * A + b * B + c * C;
        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}


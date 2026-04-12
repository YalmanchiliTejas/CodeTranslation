#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = 1LL << 40;
    for (int i = 0; i <= 2 * max(X, Y); i += 2) {
        ans = min(ans, (long long)(max(0, X - i / 2) * A + max(0, Y - i / 2) * B + i * C));
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = pow(10, 15);
    for (long long i = 0; i <= pow(10, 5); i++) {
        long long tmpans = i * 2 * C;

        if (X > i) {
            tmpans += (X - i) * A;
        }
        if (Y > i) {
            tmpans += (Y - i) * B;
        }
        ans = min(ans, tmpans);
    }
    cout << ans << endl;
    return 0;
}
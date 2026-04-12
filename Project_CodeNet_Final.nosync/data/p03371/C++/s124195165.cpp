#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;

    int ans = 1 << 30;
    for (int i = 0; i <= 100000; i++) {
        int sum = C * i + max(0, A * (X - i)) + max(0, B * (Y - i));
        ans = min(ans, sum);
    }

    cout << ans << endl;
}
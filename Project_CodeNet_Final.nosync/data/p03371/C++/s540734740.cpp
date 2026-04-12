#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 1001001001;
    for (int i = 0; i <= 100000; i++) {
        int price = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i);
        ans = min(ans, price);
    }

    cout << ans << endl;
}
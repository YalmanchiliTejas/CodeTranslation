#include <bits/stdc++.h>

using namespace std;

int main () {

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans = INT_MAX;
    for (int i = 0; i <= 100000; i++) {
        long long cost = (long long)(2 * C * i + A * max(0, X - i) + B * max(0, Y - i));
        ans = min(cost, ans);
    }
    cout << ans << endl;

    return 0;
}
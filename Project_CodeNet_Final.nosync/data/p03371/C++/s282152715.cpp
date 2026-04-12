#include <bits/stdc++.h>
using namespace std;


int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int res = INT32_MAX;
    for (int i = 0; i <= 100000; i++) {
        res = min(res, 2 * C * i + A * max(0, X - i) + B * max(0, Y - i));
    }

    cout << res << endl;
    return 0;
}
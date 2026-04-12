#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    cout << min({
        A * X + B * Y,
        C * 2 * X + B * max(0, Y - X),
        A * max(0, X - Y) + C * 2 * Y
    }) << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int n = A * X + B * Y;
    int a = X * 2 * C + abs(X - Y) * B;
    int b = Y * 2 * C + abs(X - Y) * A;
    int all = max(X, Y) * C * 2;
    cout << min({n, a, b, all}) << endl;
}

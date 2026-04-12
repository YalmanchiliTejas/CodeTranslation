#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (X > Y) {
        swap(X, Y);
        swap(A, B);
    }
    if (A + B <= 2 * C) cout << (A + B) * X + min(B, 2 * C) * (Y - X) << endl;
    else cout << X * 2 * C + min(B, 2 * C) * (Y - X) << endl;
}

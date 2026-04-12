#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int m = min(X, Y), M = max(X, Y);
    cout << min(A * X + B * Y, min(A * (X - m) + B * (Y - m) + 2 * C * m, 2 * C * M)) << endl;
}
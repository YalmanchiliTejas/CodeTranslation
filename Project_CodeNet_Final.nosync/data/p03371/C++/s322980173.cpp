#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, X, Y;
    int sum = 0;

    cin >> A >> B >> C >> X >> Y;
    if (X < Y) {
        swap(X, Y);
        swap(A, B);
    }

    sum += min(A + B, 2 * C) * Y;
    sum += min(A, 2 * C) * (X - Y);

    cout << sum << endl;
}
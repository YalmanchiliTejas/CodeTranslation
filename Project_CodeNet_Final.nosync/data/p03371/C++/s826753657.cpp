#include<iostream>
using namespace std;

int main() {
    int A, B, C, X, Y, sum = 0;
    cin >> A >> B >> C >> X >> Y;
    if (X < Y) {
        swap(X, Y);
        swap(A, B);
    }
    if (A > 2 * C) {
        sum += 2 * C * X;
    }
    else if (A + B > C * 2) {
        sum += C * 2 * Y;
        X -= Y;
        sum += A * X;
    }
    else {
        sum += A * X + B * Y;
    }
    cout << sum << endl;
    return 0;
}
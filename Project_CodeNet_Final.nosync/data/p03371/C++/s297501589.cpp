#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int  A, B, A_B, X, Y;
    cin >> A >> B >> A_B >> X >> Y;
    int sum;

    if (A + B <= A_B * 2) {
        sum = X*A + Y*B;
    }

    else {
        if (A >= A_B * 2 && B >= A_B * 2) {
            sum = A_B * 2 * max(X, Y);
        }

        else if (A >= A_B * 2) {
            if (X >= Y) {
                sum = A_B * 2 * X;
            }
            else {
                sum = (A_B * 2)*X;
                sum += B*(Y - X);
            }
        }
        else if (B >= A_B * 2) {
            if (Y >= X) {
                sum = A_B * 2 * Y;
            }
            else {
                sum = (A_B * 2)*Y;
                sum += A*(X - Y);
            }
        }
        else {
            if (X >= Y) {
                sum = A_B * 2 * Y;
                sum += A*(X - Y);
            }
            else if (Y >= X) {
                sum = A_B * 2 * X;
                sum += B*(Y - X);
            }
        }
    }
    cout << sum << endl;
}
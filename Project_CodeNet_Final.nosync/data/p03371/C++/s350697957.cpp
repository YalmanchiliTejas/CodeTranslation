#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C, X, Y;

long long first() {
    return (long long) A * X + B * Y;
}

long long second() {
    return (long long) C * 2 * max(X, Y);
}

long long third() {
    if (X > Y) {
        return (long long) C * 2 * Y + A * (X - Y);
    } else {
        return (long long) C * 2 * X + B * (Y - X);
    }
}


int main() {
    cin >> A >> B >> C >> X >> Y;

    cout << min(first(), min(second(), third())) << endl;
}
#include <iostream>
using namespace std;

int main() {
    long long A, B, C, X, Y = 0;
    cin >> A >> B >> C >> X >> Y;
    long long s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    if(X > Y) {
        s3 = 2 * Y * C + (X - Y) * A;
        s4 = 2 * X * C;
    } else {
        s3 = 2 * X * C + (Y - X) * B;
        s4 = 2 * Y * C;
    }
    s1 = A * X + B * Y;
    s2 = A * X + B * Y;
    long long min = s1;
    if(min > s2) min = s2;
    if(min > s3) min = s3;
    if(min > s4) min = s4;
    cout << min << endl;
    return 0;
}

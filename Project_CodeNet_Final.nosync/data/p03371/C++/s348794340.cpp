#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int val = A * X + B * Y;
    int minNum = min(X, Y);
    int valtemp = C * minNum * 2;
    valtemp += (X - minNum) * A + (Y - minNum) * B;
    int val2 = max(X, Y) * 2 * C;
    int ans = min(valtemp, min(val, val2));
    cout << ans << endl;
    return 0;
}
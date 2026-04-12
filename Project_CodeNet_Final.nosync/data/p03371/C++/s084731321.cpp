#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int res = 0;
    if (A + B > C*2)
    {
        int mi = min(X, Y);
        res += C * mi * 2;
        X -= mi;
        Y -= mi;
    }
    if (A > C * 2) {
        res += C * 2 * X;
        X = 0;
    }
    if ( B > C * 2) {
        res += C * 2 * Y;
        Y = 0;
    }
    res += X * A + Y * B;
    cout << res << endl;
    return 0;
}
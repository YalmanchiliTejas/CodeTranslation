#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (2 * C >= A + B)
    {
        cout << A * X + B * Y << endl;
        exit(0);
    }
    else if(X >= Y && A > 2 * C)
    {
        cout << C * X * 2 << endl;
        exit(0);
    }
    else if(X >= Y && A <= 2 * C)
    {
        cout << C * Y * 2 + A * (X-Y) << endl;
        exit(0);
    }
    else if(Y > X && B > 2 * C)
    {
        cout << C * Y * 2 << endl;
        exit(0);
    }
    else if(Y > X && B <= 2 * C)
    {
        cout << C * X * 2 + B * (Y-X) << endl;
        exit(0);
    }
}
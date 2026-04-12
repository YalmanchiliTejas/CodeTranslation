#include <bits/stdc++.h>
using namespace std;

int main()
{
    double A, B, C, X, Y;
    int sum = 0, current = 0, diff = 0, max_num;
    cin >> A >> B >> C >> X >> Y;

    diff = min(X, Y);
    current = 2 * C * diff;
    max_num = 2 * C * max(X, Y);

    if ((X - Y) > (Y - X))
    {
        current += (X - Y) * A;
    }
    else
    {
        current += (Y - X) * B;
    }
    sum = min(current, max_num);

    current = A * X + B * Y;

    sum = min(sum, current);

    cout << sum << endl;
    return 0;
}
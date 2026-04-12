#include <iostream>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int minimum = (X < Y) ? X : Y;
    int pizza_pair = ((A + B) < (2 * C)) ? (A + B) : (2 * C);
    long long res = 0;
    res = minimum * pizza_pair;

    if (X > Y)
    {
        res += (A > (2 * C)) ? ((X - Y) * 2 * C) : ((X - Y) * A);
    }
    else
    {
        res += (B > (2 * C)) ? ((Y - X) * 2 * C) : ((Y - X) * B);
    }

    cout << res << endl;

    return 0;
}
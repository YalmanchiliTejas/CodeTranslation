#include <bits/stdc++.h>
using namespace std;

template <typename T>
T gcd(T x, T y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

template <typename T>
T lcm(T x, T y)
{
    if (x == 0 || y == 0)
        return 0;
    return x / gcd(x, y) * y;
}

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X -= Z;
    cout << X / (Y + Z) << endl;
}

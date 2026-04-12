#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ll A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;

    ll a = 0;
    ll b = 0;
    ll c = 0;

    a = max(X, Y) * 2 * C;
    if(X<= Y)
    {
        b += 2 * C * X;
        b += B * (Y - X);
    }
    else
    {
        b += 2 * C * Y;
        b += A * (X - Y);
    }

    c = X * A + Y * B;

    cout << min(min(a, b), c) << endl;

    return 0;
}

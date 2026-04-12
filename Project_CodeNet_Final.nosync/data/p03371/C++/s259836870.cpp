#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;
int main(void)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int gokei = 0;
    if (A + B <= 2 * C)
    {
        gokei = X * A + Y * B;
    }
    else
    {
        int toriaezu = min(X, Y);
        gokei = 2 * C * toriaezu;
        int husoku = max(X, Y) - toriaezu;
        int sukunai = A;
        if (toriaezu == X)
        {
            sukunai = B;
        }
        if (2 * C < sukunai)
        {
            gokei += 2 * C * husoku;
        }
        else
        {
            gokei += husoku * sukunai;
        }
    }
    cout << gokei << endl;
    return 0;
}
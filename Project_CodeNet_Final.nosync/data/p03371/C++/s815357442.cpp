#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int min = numeric_limits<int>::max();

    int larger = (X >= Y) ? 2 * X : 2 * Y;
    for (int c = 0; c <= larger; c += 2)
    {
        int a = X - c / 2;
        int b = Y - c / 2;
        a = (a > 0) ? a : 0;
        b = (b > 0) ? b : 0;

        int price = A * a + B * b + C * c;

        //cout << "c: " << c << " a:" << a << " b:" << b << " price:" << price << endl;

        if (price < min)
        {
            min = price;
        }
    }

    cout << min << endl;
    return 0;
}

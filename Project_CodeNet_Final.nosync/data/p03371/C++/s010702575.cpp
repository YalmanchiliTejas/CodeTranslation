#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long ll;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int min_price = numeric_limits<int>::max();
    int num_AB = 0;
    while (X >= num_AB / 2 || Y >= num_AB / 2)
    {
        int price = max(X - num_AB / 2, 0) * A + max(Y - num_AB / 2, 0) * B + num_AB * C;
        if (price < min_price)
            min_price = price;
        num_AB += 2;
    }
    cout << min_price << endl;
}

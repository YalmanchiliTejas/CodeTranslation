#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int totalPrice = 1e9;
    for (int Z = 0; Z <= max(X, Y); Z++)
    {
        totalPrice = min(2 * C * Z + A * max(0, X - Z) + B * max(0, Y - Z), totalPrice);
    }

    cout << totalPrice << endl;
    return 0;
}
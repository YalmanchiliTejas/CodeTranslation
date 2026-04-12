#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int min_cost = A * X + B * Y;
    for (int Z = 0; Z <= 2 * max(X, Y); ++Z) {
        int cost = A * max(0, X - Z / 2) + B * max(0, Y - Z / 2) + C * Z;
        if (min_cost > cost)
            min_cost = cost;
    }
    cout << min_cost << endl;
}

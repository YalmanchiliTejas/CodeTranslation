#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;
    int min = INT_MAX;
    int res;

    for (int i = 0; i <= 1e5; i++)
    {
        res = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
        if (min > res)
        {
            min = res;
        }
    }

    cout << min;
    return 0;
}

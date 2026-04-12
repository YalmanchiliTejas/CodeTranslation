#include <bits/stdc++.h>

using namespace std;

int main()
{
    long X, Y, Z, Sum = 0;
    cin >> X >> Y >> Z;

    for (int i = 0; i <= 100000; i++)
    {
        Sum = (Y * i) + (Z * (i + 1));

        if (Sum > X)
        {
            cout << i - 1;
            break;
        }
    }
}
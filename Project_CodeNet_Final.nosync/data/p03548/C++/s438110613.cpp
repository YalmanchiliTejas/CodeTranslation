#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int i = 0;
    while (1)
    {
        int width = (i * (Z + Y) + Z);
        if (width > X)
        {
            i--;
            break;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}
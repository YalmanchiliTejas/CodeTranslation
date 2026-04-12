#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y, Z;
    cin >> X >> Y >>Z;
    cout << X / (Y + Z) - (X % (Y + Z) < Z) << endl;

    return 0;
}

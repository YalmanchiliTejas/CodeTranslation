#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int n = (X - Z) / (Y + Z);
    cout << n << endl;
    return 0;
}
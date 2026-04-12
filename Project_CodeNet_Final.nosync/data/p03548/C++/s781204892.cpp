#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    x = x - y - 2*z;
    int ans = 1 + x/(y+z);
    cout << ans << endl;
    return 0;
}
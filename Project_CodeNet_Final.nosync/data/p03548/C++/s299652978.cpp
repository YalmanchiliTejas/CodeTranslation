#include <bits/stdc++.h>
using namespace std;

long long dp[90];

int main()
{
    long long x, y, z;
    cin >> x >> y >> z;
    long long ans = 0;
    x -= z;
    while (y + z <= x)
    {
        ans++;
        x -= (y + z);
    }
    cout << ans << endl;
    return 0;
}
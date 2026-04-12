#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 1e9;
    for (int i = 0; i <= max(x, y); i++)
    {
        int cost = 2 * c * i + a * max(x - i, 0) + b * max(y - i, 0);
        if (ans > cost)
        {
            ans = cost;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll min = a * x + b * y;
    int ans;
    for (int i = 0; i < 100001; i++)
    {
        ans = i * 2 * c + max(0, x - i) * a + max(y - i, 0) * b;
        if (ans < min)
        {
            min = ans;
        }
    }
    cout << min << endl;

    return 0;
}

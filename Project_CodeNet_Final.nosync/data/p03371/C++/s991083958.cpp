#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    long long ans = 1LL << 60;
    for (int i = 0; i < 100001; i++) {
        long long t = 2 * c * i + max(x - i, 0) * a + max(y - i, 0) * b;
        ans = min(ans, t);
    }

    cout << ans << endl;

    return 0;
}

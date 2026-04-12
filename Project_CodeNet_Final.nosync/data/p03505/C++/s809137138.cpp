#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
int main()
{
    lli k, a, b;
    cin >> k >> a >> b;
    lli c = a - b;
    if (c <= 0) {
        if (k <= a) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        using ll = __int128;
        ll up = 2 * 1e18 + 10;
        ll low = -1;
        while (up - low > 1) {
            ll mid = (up + low) >> 1;
            if (mid * (a - b) + a >= k) {
                up = mid;
            } else {
                low = mid;
            }
        }
        cout << (lli)(2 * up + 1) << endl;
    }
}

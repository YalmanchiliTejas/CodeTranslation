#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
//西暦⇒時代の歴
ll a[100010];
int main()
{
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll b = 1; b <= N; ++b)
    {
        for (ll q = 0; K + b * q <= N; ++q)
        {
            ll lb = max(1LL, K + b * q);
            ll ub = min(N, b * (q + 1) - 1);
            if (lb <= ub)
                ans += ub - lb + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;
    ll ans = 100000000000;
    for (ll i = 0; i <= max(X, Y) * 2; i += 2)
    {
        ll en = i * C +
                max((ll)0, (X - i / 2)) * A +
                max((ll)0, (Y - i / 2)) * B;
        // cout << en << endl;
        ans = min(ans, en);
    }
    cout << ans << endl;
}

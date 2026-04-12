#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];

    ll mi = 0;
    int ans = 0;
    for (ll h : H)
    {
        if (mi <= h)
        {
            mi = h;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

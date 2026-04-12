#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];
    int ans = 0;
    int mx = 0;
    rep(i, 0, n) if (mx <= h[i]) ans++, mx = h[i];
    cout << ans << endl;
}

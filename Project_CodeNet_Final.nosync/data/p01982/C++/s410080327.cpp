#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (1)
    {
        int n, l, r;
        cin >> n >> l >> r;
        if (n == 0)
            break;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int ans = 0;
        for (int y = l; y <= r; y++)
        {
            bool uruu = false, f = true;
            rep(i, n) if (y % a[i] == 0)
            {
                f = false;
                if (i % 2 == 0)
                    uruu = true;
                break;
            }
            if (f && n % 2 == 0)
                uruu = true;
            if (uruu)
                ans++;
        }
        cout << ans << endl;
    }
}


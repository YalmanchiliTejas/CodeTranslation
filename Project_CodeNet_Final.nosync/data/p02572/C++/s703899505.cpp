#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

int binpow(int a, int b)
{
    int ans = 1;
    if (b == 0)
        return 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

//read question carefully!

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int pre[n];
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        int temp = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            temp += a[i];
            int dif = (sum - temp) % mod;
            ans += dif * (a[i] % mod) % mod;
            ans = ans % mod;
        }
        cout << ans << "\n";
    }
}

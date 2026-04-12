#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define help freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    int n;
    cin >> n;
    ll mod = 1000000007;
    ll prefix[n + 5];
    prefix[0] = 0;
    ll arr[n + 5];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    ll ans = 0ll;

    for (int i = 1; i <= n; i++)
    {
        ll x = (prefix[n] - prefix[i]);
        x = x % mod;
        ans = ans + (arr[i] * x);
        ans = ans % mod;
    }

    if (ans >= mod)
        ans = ans % mod;

    if (ans < 0)
        ans = ans + mod;
    cout << ans << endl;

    return 0;
}

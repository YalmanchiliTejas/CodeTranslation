#include <bits/stdc++.h>
using namespace std;
#define AB_BHI_NI_DEGI                \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define pb push_back
#define N 100009
#define inf 1e18
const double PI = 3.141592653589793238462643383279;
int mod = 1e9 + 7;
//int mod = 998244353;
#define P pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define ld long double

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;
        n = n / 2;
        a = (a * a) % mod;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    if (n >= 30)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int32_t main()
{
    AB_BHI_NI_DEGI
    int Test = 1;
    //cin >> Test;
    while (Test--)
        solve();
    return 0;
}
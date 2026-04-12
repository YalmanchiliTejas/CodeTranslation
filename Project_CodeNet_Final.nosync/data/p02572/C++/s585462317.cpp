#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
const int mmax = 200005;
ll n;
ll a[mmax];
ll f[mmax][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][1] = (f[i-1][1]+a[i])%m;
    }
    for (int i = 1; i <= n; i++)
        f[i][2] = ((f[i-1][1]*a[i])%m + f[i-1][2])%m;
    cout << f[n][2]%m;
    return 0;
}

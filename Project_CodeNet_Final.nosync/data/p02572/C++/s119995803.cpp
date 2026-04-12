#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// cout << "YES\n";
// cout << "NO\n";
int main()
{
    ll n;
    cin >> n;
    ll a[n + 5] = {0}, sfx[n + 5] = {0}, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        sfx[i] = sfx[i + 1] + a[i];
        sum += (sfx[i] % mod * a[i - 1] % mod);
    }
    cout << sum % mod << endl;
    return 0;
}
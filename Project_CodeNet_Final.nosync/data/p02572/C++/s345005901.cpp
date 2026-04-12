#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll pre[n - 1];
    pre[n - 2] = a[n - 1];
    for (int i = n - 2, k = n - 3; i >= 0 && k >= 0; i--, k--)
    {
        pre[k] = (pre[k + 1]%mod + a[i]%mod)%mod;
    }
    ll prod = 0;
    for (int i = 0, j = 0; i < n - 1 && j < n; i++, j++)
    {
        prod += a[j] * pre[i];
        if(prod<0) prod+=mod;
        prod %= mod;
    }
    cout << prod;
    return 0;
}
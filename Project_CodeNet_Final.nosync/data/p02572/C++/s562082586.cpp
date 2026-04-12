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
    ll a[n];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }
    ll prod = 0;
    for (int i = 0; i < n; i++)
    {

        sum -= a[i];
        if(sum<0) sum+=mod;
        prod += a[i] * sum;
        prod %= mod;
    }
    cout << prod;
    return 0;
}
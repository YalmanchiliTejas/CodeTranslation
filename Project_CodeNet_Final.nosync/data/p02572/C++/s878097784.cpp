#include<bits/stdc++.h>
#define lli   long long int
#define pb push_back
#define rep(i,s,n) for(lli i=s;i<n;i++)
#define irep(i,n,s) for(lli i=n-1;i>=s;i--)
#define mp make_pair
#define mod 1000000007
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    lli i, j, k, m, n;
    // cin >> t;


    cin >> n;
    vector<lli>v(n);
    lli a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    lli sum = 0;
    for (i = n - 1; i >= 0; i--)
    {
        v[i] = sum;
        sum += a[i];
        sum %= mod;
    }
    lli res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] * v[i]) % mod;
        res = res % mod;
    }
    cout << res << "\n";








}



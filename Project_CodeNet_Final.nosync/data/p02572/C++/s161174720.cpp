#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define vec vector<long long int>
#define fi first
#define se second
#define pb push_back
int main()
{
    int n;
    cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        x.pb(t);
    }
    ll ans = 0;
    ll sum = x[0];
    for (int i = 1; i < n; i++)
    {
        ans = (ans % mod + (sum % mod * x[i] % mod) % mod) % mod;
        sum = sum + x[i];
    }
    cout << ans;
}
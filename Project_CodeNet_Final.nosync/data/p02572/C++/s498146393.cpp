#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        sum -= a[i];
        ans = (ans + (sum % mod) * (a[i] % mod)) % mod;
    }
    cout << ans << "\n";
}
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200000;
const int mod = 1000000007;

int n;
long long a[N + 1];
long long pref[N + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        pref[i] %= mod;
    }
    
    long long ans = 0;
    for (int i = n; i >= 2; i--)
        ans = (ans + a[i] * pref[i - 1]) % mod;
    
    cout << ans;
    
    return 0;
}

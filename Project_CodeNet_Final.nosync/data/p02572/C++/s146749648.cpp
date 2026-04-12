#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCases = 1;
   // cin >> testCases;
    
    while(testCases--)
    {
        int n,i;
        cin >> n;
        int a[n + 1];
        int suf[n + 2] = {0};
        
        for(i = 1;i <= n;++i)
            cin >> a[i];
            
        for(i = n;i >= 1;--i)
        {
            suf[i] = (suf[i + 1] + a[i]) % mod;
        }
        
        int ans = 0;
        
        for(i = 1;i <= n;++i)
        {
            ans += (a[i] * suf[i + 1]) % mod;
            ans %= mod;
        }
        
        cout << ans;
        cout << '\n';
    }
    
}

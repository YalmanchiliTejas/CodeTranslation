#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k,ans;
    while(cin >> n >> k)
    {
        if(k == 0)
        {
            cout << n*n << '\n';
            continue;
        }
        
        ans = 0;
        for(ll i = k+1; i <= n; i++)
        {
            ll aux = i-k;
            ans += aux * (n/i);
            aux = n%i;
            if(aux > 0)
                ans += max(0LL, aux - k + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
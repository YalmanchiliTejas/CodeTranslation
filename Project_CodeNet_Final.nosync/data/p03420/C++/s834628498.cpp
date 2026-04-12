#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll ans = 0;


int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    
    for(ll i = 1;i <= n;i++){
        if(i - 1 >= k){
            ans += n / i * max((i - k), 0LL);
        }
        if(n % i != 0){
            ll t = 0;
            if(k != 0){
                t++;
            }
            ans += max(n % i - k + t, 0LL);
        }
    }

    cout << ans;

    return 0;
}
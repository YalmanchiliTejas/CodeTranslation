#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const unsigned int mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    
    int n,num,val;
    cin >> n;
    ll a[n];
    ll pref[n];
    cin >> num;
    a[0] = num;
    pref[0]= num;
    for(int i = 1; i < n; i++)
    {
        cin >> val;
        val = val % mod;
        a[i] = val;
    }
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            pref[i] = a[i] % mod;
        }
        else
        {
            pref[i] = (pref[i-1] + a[i]) % mod;
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        ll m;
        m = (a[i]*(pref[n-1] - pref[i])) % mod;
        sum += m;
        sum = sum % mod;
    }
    if(sum < 0){
        cout << (sum + mod) << "\n" ;
    }
    else{
        cout << sum << "\n" ;
    }
}

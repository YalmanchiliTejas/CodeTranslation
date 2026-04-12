//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll sum = 0;
    ll ans = 0;
    for(ll i=0;i<N;++i)
    {
        ll val; cin>>val;
        if(i == 0)
        {
            sum = val;
            continue;
        }
        
        ans = (ans + val*sum) % MOD;
        sum = (sum + val) % MOD;
        
    }
    
    cout<<ans<<endl;
}
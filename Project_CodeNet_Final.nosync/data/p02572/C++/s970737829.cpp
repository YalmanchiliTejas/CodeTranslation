#include <iostream>

using namespace std;

#define ll long long 

int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll dp[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[n-1]=arr[n-1];
    for(ll i=n-2;i>=0;i--){
        dp[i]=(dp[i+1]+arr[i])%1000000007;
    }
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ans+=((arr[i]*dp[i+1])%1000000007);
        ans=ans%1000000007;
    }
    
    cout<<ans<<"\n";

    return 0;
}

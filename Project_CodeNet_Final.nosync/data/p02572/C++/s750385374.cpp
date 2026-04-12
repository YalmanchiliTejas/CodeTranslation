#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<ll>arr(n);
    ll sum1=0,sum2=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum1=(sum1+arr[i])%mod;
        sum2=(sum2+arr[i]*arr[i]%mod)%mod;
    }
    sum1=sum1*sum1%mod;
    ll ans=(sum1-sum2+mod)%mod;
    ans=(ans*500000004%mod)%mod;
    cout<<ans;

    return 0;

    
}
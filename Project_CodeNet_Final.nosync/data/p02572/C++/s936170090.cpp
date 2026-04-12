#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> vec(n);
    long long sum=0;
    long long ans=0;
    long long mod=1e9+7;
    for(auto &e:vec)
    {
        cin>>e;
        sum+=e;
    }
    sum=sum%mod;
    for(int i=0;i<n;i++)
    {
        sum=(sum-vec[i]+mod)%mod;
        ans=ans+((vec[i]%mod)*(sum%mod))%mod;
        ans=ans%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
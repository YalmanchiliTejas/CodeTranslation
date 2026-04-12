#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    long long wa[n];
    wa[0]=a[0];
    for(int i=0;i<n-1;i++)wa[i+1]=(wa[i]+a[i+1])%mod;
    long long ans=0;
    for(int i=1;i<n;i++)ans=(ans+a[i]*wa[i-1])%mod;
    cout<<ans<<endl;
    return 0;
}
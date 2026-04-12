#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long arr[n];
    long long sum[n+1];
    sum[0]=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum[i+1]=arr[i]+sum[i];
    }
    long long ans=0;
    long long mod=1e9+7;
    for(int i=0; i<n; i++){
        // cout<<arr[i]<<" "<<sum[n]<<" "<<sum[i+1]<<endl;
        ans=(ans%mod+((arr[i]%mod)*((sum[n]-sum[i+1])%mod))%mod)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
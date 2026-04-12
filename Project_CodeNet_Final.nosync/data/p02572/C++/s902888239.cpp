#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int32_t main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int suffixSum[n+1];
    for(int i=n;i>=1;i--){
        if(i==n){
            suffixSum[i]=a[i];
        } else{
            suffixSum[i]=a[i]+suffixSum[i+1];
            suffixSum[i]%=mod;
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=(a[i]*suffixSum[i+1])%mod;
    }
    cout<<ans%mod;
}
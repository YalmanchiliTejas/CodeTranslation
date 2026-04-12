#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    int a[n];
    ll sum=0;
    for(int i=0;i<n;i++)    cin>>a[i],sum+=a[i];
    ll ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        ans+=((a[i]%mod)*(sum%mod))%mod;
    }
    ans%=mod;
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mod=1000'000'007;
    vector<int> a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=(sum+a[i])%mod;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ans=(ans+a[i]*sum)%mod;
    }
    cout<<ans<<endl;
    return 0;
}

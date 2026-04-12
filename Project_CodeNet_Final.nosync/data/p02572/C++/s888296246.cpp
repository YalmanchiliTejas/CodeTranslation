#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int mod = 1000000007;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        sum%=mod;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ans+=(a[i]*sum);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

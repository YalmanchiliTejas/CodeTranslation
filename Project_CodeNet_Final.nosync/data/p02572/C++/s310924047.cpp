#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[200010];
int main() {
    int n;
    cin>>n;
    long long sum=0,ans=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        ans=(ans+a[i]*sum)%mod;
        sum=(sum+a[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
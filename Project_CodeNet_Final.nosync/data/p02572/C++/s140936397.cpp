#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int main() {
    ios::sync_with_stdio(0);
     cin.tie(0);
    cout.tie(0);
     long long t,a[200010],tem=0,ans=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a[i];
        tem+=a[i];
    }
    for(int i=1;i<t;i++){
            tem-=a[i];
        ans=(ans+(a[i]*(tem%mod))%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}



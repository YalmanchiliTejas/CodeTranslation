#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
signed main(){
    int n,a,sum=0,ans=0;
    cin>>n;
    while(cin>>a){
        (ans+=a*sum)%=mod;
        (sum+=a)%=mod;
    }
    cout<<ans<<endl;
}

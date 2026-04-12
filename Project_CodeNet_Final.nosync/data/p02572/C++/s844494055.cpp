#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
const int inv2=500000004
;
signed main(){
    int n, ans=0, sum=0, a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        sum=(sum+a*a%mod)%mod;
        ans=(ans+a)%mod;
    }
    ans=ans*ans%mod;
    ans-=sum;
    ans=(ans%mod+mod)%mod;
    cout<<(ans*inv2%mod)<<endl;
}
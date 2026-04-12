#include "bits/stdc++.h"
using namespace std;

#define int long long 

const int mod=1e9+7;

int bm(int x,int p){
    if(p==1)return x;
    if(p==0)return 1;
    if(p&1) return (x*bm(x,p-1))%mod;
    int f=bm(x,p/2);
    return (f*f)%mod;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];

    long long sum=0;

    for(int& i : a){
        cin >> i;
        sum+=i;
        sum%=mod;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+a[i]*(sum-a[i]+mod)%mod)%mod;
    }
    ans=(ans*bm(2,mod-2))%mod;
    cout<<ans<<endl;

}


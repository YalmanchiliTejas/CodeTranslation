#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
const int mod=1e9+7;
int a[maxn];
int sum[maxn];
signed  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sum[n+1]=0;
    for(int i=n;i>=2;i--){
        sum[i]=(sum[i+1]+a[i])%mod;
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
            //cout<<sum[i+1]<<endl;
        ans=(ans+a[i]*sum[i+1])%mod;
    }
    cout<<ans<<endl;

    return 0;
}



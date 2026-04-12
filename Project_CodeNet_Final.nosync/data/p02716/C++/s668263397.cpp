#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n+1);
    rep1(i,n) cin>>a[i];
    ll sum[n+1],dp[n+1];
    rep(i,n+1){
        sum[i]=0;
        dp[i]=0;
    }
    
    sum[1]=a[1];
    for(int i=3;i<=n;i+=2) sum[i]=sum[i-2]+a[i];
    for(int i=2;i<=n;i++){
        if(i%2==1) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else dp[i]=max(sum[i-1],dp[i-2]+a[i]);
        //cout<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;
}

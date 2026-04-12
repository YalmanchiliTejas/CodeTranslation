#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int n,s;
int a[3005];
int dp[3005],ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=s-a[i];j>0;j--){
            dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
        }
        dp[a[i]]=(dp[a[i]]+i)%mod;
        ans=(ans+dp[s])%mod;
    }
    cout<<ans<<endl;

    return 0;
}
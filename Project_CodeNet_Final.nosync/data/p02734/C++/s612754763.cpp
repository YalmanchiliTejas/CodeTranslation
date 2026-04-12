#include <bits/stdc++.h>
#define N 3005
typedef long long ll;
using namespace std;

const ll mod=998244353;

ll a[N],dp[N][N];

int main(){
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        dp[i][0]++;
        for(int j=0;j<=3000;j++) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
        for(int j=0;j<=3000;j++){
            if(j+a[i]>3000) continue;
            dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%mod;
        }

    }
    for(int i=1;i<=n+1;i++){
        ans+=dp[i][s]; ans%=mod;
    }
    cout<<ans<<endl;
}

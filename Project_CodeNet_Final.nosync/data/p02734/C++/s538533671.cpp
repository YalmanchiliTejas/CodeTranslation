//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 998244353
typedef long long int ll;
using namespace std;
#define MAX 3001
ll dp[MAX][MAX];
ll pre[MAX][MAX];
ll arr[MAX+3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, s; cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        dp[i][arr[i]]=i;
        for(int j=arr[i]+1;j<MAX;j++){
            dp[i][j]=pre[i-1][j-arr[i]] ;
        }
        
        for(int j=1;j<MAX;j++) pre[i][j]=(pre[i-1][j]+dp[i][j])%mod;
         ans=(ans+(dp[i][s]*(n-i+1))%mod)%mod;
    }
    cout<<ans<<endl;
}
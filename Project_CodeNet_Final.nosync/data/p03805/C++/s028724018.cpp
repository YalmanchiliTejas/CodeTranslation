#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,dp[8][8],a,b,ans;
void dfs(ll x,ll y){
    if(y==(1<<n)-1){ans++;return ;}
    for(int i=0;i<n;i++){
        //cout<<dp[x][i]<<" "<<((1<<i)&y)<<endl;
        if(dp[x][i]&&(!((1<<i)&y)))dfs(i,y|(1<<i));
    }
    return ;
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        dp[a][b]++;
        dp[b][a]++;
    }
    dfs(0,1);
    cout<<ans<<endl;
}

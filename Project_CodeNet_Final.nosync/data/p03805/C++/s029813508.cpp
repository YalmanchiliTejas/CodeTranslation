#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,dp[8][8],a,b,ans,used[8];
void dfs(ll x,ll y){
    if(y==n)ans++;
    used[x]=1;
    for(int i=0;i<n;i++){
        //cout<<dp[x][i]<<" "<<((1<<i)&y)<<endl;
        if(!used[i]&&dp[x][i])dfs(i,y+1);
    }
    used[x]=0;
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

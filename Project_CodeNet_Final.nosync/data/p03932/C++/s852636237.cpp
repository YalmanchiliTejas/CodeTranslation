#include <bits/stdc++.h>
#define maxn 209
using namespace std;
int n,m;
int a[maxn][maxn];
long long dp[maxn][maxn][maxn];
int dx[]={1,0};
int dy[]={0,1};
const long long INF=1e18;
bool in(int x,int y){
    return 1<=x&&x<=n&&1<=y&&y<=m;
}
long long dfs(int x,int y,int z){
    if(!in(x,y)||!in(z,x+y-z))
        return -INF;
    if(x==n&&y==m&&z==n)
        return a[x][y];
    long long &ans=dp[x][y][z];
    if(ans!=-1) return ans;
    int add;
    if(x==z)
        add=a[x][y];
    else
        add=a[x][y]+a[z][x+y-z];
    ans=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans=max(ans,dfs(x+dx[i],y+dy[i],z+dx[j]));
        }
    }
    ans+=add;
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,1,1)<<endl;
    return 0;
}

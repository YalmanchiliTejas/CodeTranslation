#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int N=2005,inf=1e9;
int dp[N][N],a[3*N],mx[N],n,cnt=0,ans=0;

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n ;
    for(int i=0;i<3*n;i++)
        cin >> a[i];
    fill(*dp,*dp+N*N,-inf);
    dp[a[0]][a[1]]=0,dp[a[1]][a[0]]=0;
    mx[a[0]]=a[1],mx[a[1]]=a[0];
    for(int i=1;i<n;i++){
        int v[]={a[3*i-1],a[3*i],a[3*i+1]};
        vector <tuple <int,int,int> > vec;
        auto udt=[&](int x,int y,int z){
        	vec.push_back({x,y,z});
        };
        sort(v,v+3);
        if(v[0]==v[2]){
            cnt++;continue;
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<j;k++)udt(v[j],v[k],ans);
            for(int k=1;k<=n;k++)udt(k,v[j],dp[k][mx[k]]);
        }
        if(v[0]==v[1]){
            int x=v[0],y=v[2];
            for(int k=1;k<=n;k++){
            	udt(y,k,dp[x][k]+1);
            }
        }
        if(v[1]==v[2]){
            int x=v[1],y=v[0];
            for(int k=1;k<=n;k++){
            	udt(y,k,dp[x][k]+1);
            }
        }
        for(int j=0;j<3;j++){
            int x=v[j],y=v[(j+1)%3],z=v[(j+2)%3];
            udt(y,z,dp[x][x]+1);
        }
        for(auto [x,y,z]:vec){
        	dp[x][y]=max(dp[x][y],z),dp[y][x]=dp[x][y];
            ans=max(ans,z);
            if(dp[x][y]>dp[x][mx[x]])mx[x]=y;
            if(dp[x][y]>dp[y][mx[y]])mx[y]=x;
        }
    }
    ans=max(ans,dp[a[3*n-1]][a[3*n-1]]+1);
    cout << ans+cnt;
}

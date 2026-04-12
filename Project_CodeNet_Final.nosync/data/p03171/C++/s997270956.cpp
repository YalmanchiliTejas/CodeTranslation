#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define float double
const int  LMT =1000000000+5;
#define int long long 
#define lp(i,n) for( i=0;i<n;i++)
const int N=3001,M=100005;
int n,m,a[N],i,j,k=0;
int dp[N][N][2];bool vis[N][M];
int  solve(int i ,int j,int turn){
if(i>j)return 0;
if(dp[i][j][turn]!=-1)return dp[i][j][turn];
if(turn==1) return dp[i][j][turn]=max(a[i]+solve(i+1,j,0),a[j]+solve(i,j-1,0));
return dp[i][j][turn]=min(solve(i+1,j,1),solve(i,j-1,1));
}
int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
 #endif
 cin>>n;
 memset(dp,-1,sizeof(dp));
 lp(i,n)cin>>a[i],k+=a[i];
 
 cout<<2*solve(0,n-1,1)-k<<endl;
} 
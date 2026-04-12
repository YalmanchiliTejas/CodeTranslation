#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[3000][3000][2];
int n; 
int a[3000];
int solve(int i,int j, bool turn){
    if(i>j){
        return 0;
    }
    if(dp[i][j][turn]!=-1){
        return dp[i][j][turn];
    }
    if(turn){
    return dp[i][j][1]=max(a[i]+solve(i+1,j,0), a[j]+solve(i,j-1,0));
    }
    return dp[i][j][0]=min(solve(i+1,j,1), solve(i,j-1,1));
}
int32_t main() {
  cin>>n;
  memset(dp, -1, sizeof dp);
  int sum=0;
  for(int i=0;i<n;++i){
      cin>>a[i];
      sum+=a[i];
  }
     int x=solve(0,n-1, 1);
     int y=sum-x;
     cout<<x-y;





return 0;
}

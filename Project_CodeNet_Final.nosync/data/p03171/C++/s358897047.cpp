#include<bits/stdc++.h>
using namespace std;
int n,a[3333];
long long int memo[3333][3333][2];
long long int dp(int x,int y,int z){
  if(memo[x][y][z]!=-1) return memo[x][y][z];
  if(x>y) return 0;
  if(z==0) return memo[x][y][z]=max(dp(x+1,y,1)+a[x],dp(x,y-1,1)+a[y]);
  if(z==1) return memo[x][y][z]=min(dp(x+1,y,0)-a[x],dp(x,y-1,0)-a[y]);
}
int main(){
  memset(memo,-1,sizeof(memo));
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<dp(0,n-1,0)<<endl;
  return(0);
}

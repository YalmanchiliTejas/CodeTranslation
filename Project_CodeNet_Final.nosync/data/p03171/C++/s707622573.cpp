#include<bits/stdc++.h>
using namespace std;
long dp[3001][3001][2];
long solve(vector<long>&v,long i,long j,long turn){
        if (i>j)
           return 0;
        if (dp[i][j][turn]!=-1)
          return dp[i][j][turn];
       if (turn)
       return  dp[i][j][turn]=max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
       else
         return dp[i][j][turn]=min(solve(v,i+1,j,1),solve(v,i,j-1,1));
}

int main(){
     long n,a,s=0;
  cin>>n;
  vector<long>v;
  for (long i=0;i<n;i++){
    cin>>a;v.push_back(a);
  s+=a;
  }
  memset(dp,-1,sizeof(dp));
  long X=solve(v,0,n-1,1);
  long Y=s-X;
  cout<<X-Y<<endl;
 return 0; 
}
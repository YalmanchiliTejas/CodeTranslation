#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int dp[5001][5001],a[5001],n,ans=2;
unordered_map<int,int>M;

int main(){
  cin>>n;
  r(i,n)cin>>a[i];
  sort(a,a+n);
  r(i,n)M[a[i]]=i;

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){

      dp[i][j] = max( dp[i][j] , 2 );
      ans = max( ans , dp[i][j] );
      int nex = a[j]+(a[j]-a[i]);

      if(M.count(nex)){
        int idx = M[nex];
        dp[j][idx] = max( dp[j][idx] , dp[i][j]+1 );
      }
    }
  }
  cout<< ans <<endl;
}

#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int dp[111111],n,m,a[111];

int main(){
  while(cin>>n>>m,n){
    vector<int>v;
    r(i,n)cin>>a[i];
    r(i,(1<<n)){
      int f=0;
      r(j,n)if(i&(1<<j))f+=a[j];
      v.push_back(f);
    }
    r(i,111111)dp[i]=1e9;
    dp[0]=0;
    r(i,m+1){
      r(j,(1<<n)){
        if(i+v[j]>=m+100)continue;
        dp[i+v[j]]=min(dp[i+v[j]],dp[i]+1);
      }
    }
    cout<<dp[m]<<endl;
  }
}

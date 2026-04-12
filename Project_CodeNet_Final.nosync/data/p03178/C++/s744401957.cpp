#include<bits/stdc++.h>
using namespace std;
int main(){
  string k;
  int d;
  cin>>k>>d;
  reverse(k.begin(),k.end());
  int p=1000000007;
  vector<vector<int64_t>> dp(k.size()+1,vector<int64_t>(d,0));
  vector<vector<int64_t>> dp9(k.size()+1,vector<int64_t>(d,0));
  dp[0][0]=1;
  dp9[0][0]=1;
  for(int i=1;i<=k.size();i++){
    for(int j=0;j<d;j++){
      for(int x=0;x<10;x++){
        if(x<k.at(i-1)-'0')
          dp[i][j]=(dp[i][j]+dp9[i-1][(j-x+d*10)%d])%p;
        else if(x==k.at(i-1)-'0')
          dp[i][j]=(dp[i][j]+dp[i-1][(j-x+d*10)%d])%p;
        dp9[i][j]=(dp9[i][j]+dp9[i-1][(j-x+d*10)%d])%p;
      }
    }
  }
  cout<<(dp[k.size()][0]-1+p)%p<<endl;
}
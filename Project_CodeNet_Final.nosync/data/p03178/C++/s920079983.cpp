#include<bits/stdc++.h>
using namespace std;
string s;
long long mod=1000000007;
int d;
int dp[2][100009][109];

int main(){
  cin >> s >> d;
  dp[0][0][0]=1;
  int n=s.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      for(int k=0;k<d;k++){
        dp[1][i+1][(k+j)%d]=(dp[1][i+1][(k+j)%d]+dp[1][i][k])%mod;
        if(j>s[i]-'0')continue;
        else if(j<s[i]-'0')dp[1][i+1][(k+j)%d]=(dp[1][i+1][(k+j)%d]+dp[0][i][k])%mod;
        else dp[0][i+1][(k+j)%d]=(dp[0][i+1][(k+j)%d]+dp[0][i][k])%mod;
      }
    }
  }
  long long k=(dp[0][n][0]+dp[1][n][0])%mod;
  if(k==0){k+=mod;}
  cout << k-1 << endl;
}
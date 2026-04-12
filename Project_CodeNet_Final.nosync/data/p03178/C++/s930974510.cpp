#include<bits/stdc++.h>
using namespace std;
string s;
long long mod=1000000007;
int d;
int dp[2][100009][109];

int main(){
  cin >> s >> d;
  //はじめは未確定で、mで割った余りが0
  dp[0][0][0]=1;
  int n=s.size();
  //上からみていく
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      for(int k=0;k<d;k++){
        //確定しているものの遷移
        dp[1][i+1][(k+j)%d]=(dp[1][i+1][(k+j)%d]+dp[1][i][k])%mod;
        //未確定なものの遷移
        if(j>s[i]-'0')continue;
        //s[i]より小さければ確定に遷移
        else if(j<s[i]-'0')dp[1][i+1][(k+j)%d]=(dp[1][i+1][(k+j)%d]+dp[0][i][k])%mod;
        //s[i]と等しければ未確定に遷移
        else dp[0][i+1][(k+j)%d]=(dp[0][i+1][(k+j)%d]+dp[0][i][k])%mod;
      }
    }
  }
  long long k=(dp[0][n][0]+dp[1][n][0])%mod;
  if(k==0){k+=mod;}
  cout << k-1 << endl;
}
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int mod = 1000000007;
long long dp[100000][2][100];
//dp[i][j][k] ：i桁目までの和をdで割った時の余りがkのとなる数の個数
//i;i桁目まで
//j;未満ふらぐ
//k;i桁目までの和の%dの値
//dp[i+1][j][k] = dp[i][j][k-xx] +  

int main() {
  string k;
  int d;
  cin >> k >>d;
  //s[0] - '0'
  //cout << k[0] - '0' << endl;
  for(int i = 0;i<= k[0] - '0';i++){
    //cout << i << endl;
    if(i != k[0] - '0'){
      dp[0][1][i%d] += 1;
    }else{
      dp[0][0][i%d] += 1;
    }
  }
  //cout << dp[0][1][0] + dp[0][0][0] << endl; 
  
  int s;
  for(int i = 1;i < k.size();i++){
    s = k[i] -'0';
    //cout << s << endl;
    for(int amari = 0;amari < d;amari++){
      for(int j = 0;j<=9;j++){
        dp[i][1][(amari+j)%d] += dp[i-1][1][amari];
        dp[i][1][(amari+j)%d] %= mod;
        //cout << dp[i][1][(amari+j)%d]  << " " << " " << j << " " << amari << " " << (amari+j)%d<< endl;
        //cout << j << " " << amari << " " << (amari+d-j%d)%d << " "  << dp[i][1][amari] << " " << dp[i-1][1][(amari+d-j%d)%d] << endl;
      }
      for(int j = 0;j< s;j++){
        dp[i][1][(amari+j)%d] += dp[i-1][0][amari];
      }
      dp[i][0][(amari+s)%d] += dp[i-1][0][amari];
    }
  }
  cout << (dp[k.size()-1][0][0] + dp[k.size()-1][1][0] -1)%mod;
}

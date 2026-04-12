#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long lli;

const lli MOD = 1000000;
int n;
string str[1000];
vector<string> pat[4];

void init(){
  for(int i=0;i<4;i++) pat[i].clear();
  pat[0].push_back("0xxxxxxx");

  pat[1].push_back("110yyyyx");
  pat[1].push_back("10xxxxxx");

  pat[2].push_back("1110yyyy");
  pat[2].push_back("10yxxxxx");
  pat[2].push_back("10xxxxxx");

  pat[3].push_back("11110yyy");
  pat[3].push_back("10yyxxxx");
  pat[3].push_back("10xxxxxx");
  pat[3].push_back("10xxxxxx");
}

void solve(){
  lli dp[1001][4][4][8][2];
  for(int i=0;i<n;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++) for(int l2=0;l2<8;l2++) for(int l=0;l<2;l++) dp[i][j][k][l2][l] = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      if(pat[j][0][0] == '1' && str[i][0] != '0' || pat[j][0][0] == '0' && str[i][0] != '1'){
        int pos = pat[j][0][0] == '0';
        if(i == 0) dp[i][j][0][0][pos] = 1;
        else{
          for(int k=0;k<4;k++) dp[i][j][0][0][pos] = (dp[i][j][0][0][pos] + dp[i-1][k][k][7][1]) % MOD;

          for(int k=0;k<j;k++)
            for(int l=0;l<2;l++)
              dp[i][j][k+1][0][l] = (dp[i][j][k+1][0][l] + dp[i-1][j][k][7][l]) % MOD;
        }
      }
    }

    for(int j=0;j<4;j++){
      for(int k=0;k<=j;k++){
        for(int l=1;l<8;l++){
          for(int l2=0;l2<2;l2++){
            if(pat[j][k][l] == '1' && str[i][l] != '0' || pat[j][k][l] == '0' && str[i][l] != '1') dp[i][j][k][l][l2] = (dp[i][j][k][l][l2] + dp[i][j][k][l-1][l2]) % MOD;
            if(pat[j][k][l] == 'y'){
              if(str[i][l] == '0' || str[i][l] == 'x') dp[i][j][k][l][l2] = (dp[i][j][k][l][l2] + dp[i][j][k][l-1][l2]) % MOD;
              if(str[i][l] == '1' || str[i][l] == 'x') dp[i][j][k][l][1] = (dp[i][j][k][l][1] + dp[i][j][k][l-1][l2]) % MOD;
            }
            if(pat[j][k][l] == 'x'){
              if(str[i][l] == 'x') dp[i][j][k][l][l2] = (dp[i][j][k][l][l2] + dp[i][j][k][l-1][l2] * 2) % MOD;
              else dp[i][j][k][l][l2] = (dp[i][j][k][l][l2] + dp[i][j][k][l-1][l2]) % MOD;
            }
          }
        }
      }
    }
  }

  lli ans = 0;
  for(int i=0;i<4;i++) ans = (ans + dp[n-1][i][i][7][1]) % MOD;
  cout << ans << endl;

}

int main(){
  init();
  while(cin >> n && n){
    for(int i=0;i<n;i++) cin >> str[i];
    solve();
  }
}
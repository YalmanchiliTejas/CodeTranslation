#include <iostream>
#include <cstring>
using namespace std;

int t[10][10];
int dp[10][2000];
int score[] = {0, 60, 70, 80};
bool nothing[10][10];

int toint(int *s){
  int res = 0;

  for(int i = 4; i >= 0; i--){
    res <<= 2;
    res |= s[i];
  }

  return res;
}

void totable(int x, int *s){
  for(int i = 0; i < 5; i++){
    s[i] = (x & 3);
    x >>= 2;
  }
}

int solve(){
  int before[10], next[10], tmp[10];
  memset(dp, -1, sizeof(dp));

  dp[0][toint(t[0])] = 0;

  //3¾¯Ê
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 1024; j++){
      if(dp[i][j] == -1) continue;

      totable(j, before);

      for(int k = 0; k < 256; k++){
        totable(k, tmp);

        int sum = 0;

        for(int l = 0; l < 5; l++){
          int top = before[l];
          if(l - 1 >= 0) top = (top + tmp[l - 1]) % 4;
          if(l < 4)      top = (top + tmp[l]) % 4;

          int bottom = t[i + 1][l];
          if(l - 1 >= 0) bottom = (bottom + tmp[l - 1]) % 4;
          if(l < 4)      bottom = (bottom + tmp[l]) % 4;

          if(!nothing[i][l]) sum += score[top];
          if(!nothing[i + 1][l] && i == 3) sum += score[bottom]; //ÁÊ

          next[l] = bottom;
        }

        int nextInt = toint(next);
        dp[i + 1][nextInt] = max(dp[i + 1][nextInt], dp[i][j] + sum);
      }
    }
  }

  int res = 0;
  for(int i = 0; i < 1024; i++){
    res = max(res, dp[4][i]);
  }

  cout << res << endl;
}

int main(){
  int T;
  cin >> T;

  while(T--){
    memset(nothing, 0, sizeof(nothing));

    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        cin >> t[i][j];
        if(t[i][j] == 0){
          nothing[i][j] = true;
        }
        else{
          t[i][j]--;
        }
      }
    }

    solve();
  }
}
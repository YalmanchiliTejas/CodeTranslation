#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  string S;
  cin >> S;
  int N; N = S.size();
  int K; cin >> K;

  vector<vector<ll>> dp1(N, vector<ll>(K+1, 0));
  vector<vector<ll>> dp2(N, vector<ll>(K+1, 0));

  // 初期化
  int d0 = S[0] - '0';
  for(int i = 0; i <= d0; i++){
    if(i == d0){
      dp2[0][1]++;
    } else { 
      if(i == 0){
        dp1[0][0]++;
      } else {
        dp1[0][1]++;
      }
    }
  }

  for(int i = 0; i < N-1; i++){
    int d = S[i+1] - '0';
    for(int j = 0; j <=K; j++){
      for(int k = 0; k <= d; k++){
        if(k == d){
          if(k == 0){
            dp2[i+1][j] += dp2[i][j];
          } else {
            if(j+1<=K) dp2[i+1][j+1] += dp2[i][j];
          }
        } else { 
          if(k == 0){
            dp1[i+1][j] += dp2[i][j];
          } else {
            if(j+1<=K) dp1[i+1][j+1] += dp2[i][j];
          }
        }
      }
    }
  }

  for(int i = 0; i < N-1; i++){
    for(int j = 0; j <= K; j++){
      for(int k = 0; k <= 9; k++){
        if(k == 0){
          dp1[i+1][j] += dp1[i][j];
        } else { 
          if(j+1<=K) dp1[i+1][j+1] += dp1[i][j];
        }
      }
    }
  }
  cout << dp1[N-1][K] + dp2[N-1][K] << endl;
}

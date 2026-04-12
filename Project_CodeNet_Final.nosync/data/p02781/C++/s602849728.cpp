#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  int K;
  cin >> K;
  
  vector<vector<ll>> dp1(N, vector<ll>(K+1, 0)); // N以下確定
  vector<vector<ll>> dp2(N, vector<ll>(K+1, 0)); // N以下未確定

  int num = S[0] - '0';
  dp1[0][1] = num -1; // 1 ~ S[i]-1
  dp1[0][0] = 1; // 0
  dp2[0][1] = 1; // S[i]

  // dp2の更新
  for(int i = 0; i < N-1; i++){
    int num = S[i+1] - '0'; 
    if(num == 0){
      for(int j = 0; j <= K; j++){
        dp2[i+1][j] += dp2[i][j];
      } 
    } else { 
      for(int j = 0; j <= K; j++){
        if(j+1<=K) dp2[i+1][j+1] += dp2[i][j]; // S[i]
        if(j+1<=K) dp1[i+1][j+1] += dp2[i][j] * (num -1); // 1 ~ S[i] -1
        dp1[i+1][j] += dp2[i][j]; // 0
      }
    }
  }

  for(int i = 0; i < N-1; i++){
    for(int j = 0; j <= K; j++){
      if(j+1<=K) dp1[i+1][j+1] += dp1[i][j] * 9; // 1 ~ 9;
      dp1[i+1][j] += dp1[i][j]; // 0
    }
  }


  cout << dp1[N-1][K] + dp2[N-1][K] << endl;


}
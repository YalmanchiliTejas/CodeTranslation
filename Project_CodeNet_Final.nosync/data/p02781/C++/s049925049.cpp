#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string N;int K;ll dp0[1010][5],dp1[1010][5];
  cin >> N >> K;
  dp0[1][0] = 1; dp0[1][1] = (N[0]-'0') - 1; dp0[1][2] = 0; dp0[1][3] = 0;
  dp1[1][0] = 0; dp1[1][1] = 1; dp1[1][2] = 0; dp1[1][3] = 0;
  for(int i = 2; i <= N.size();i++){
    dp0[i][0] = dp0[i-1][0];
    for(int j = 1; j <= K; j++){
      dp0[i][j] = dp0[i-1][j-1] * 9 + dp0[i-1][j] + dp1[i-1][j-1]*max(N[i-1]-'0'-1,0)+dp1[i-1][j]*((N[i-1]-'0'>0));
      dp1[i][j] = dp1[i-1][j-1]*min(N[i-1]-'0',1)+dp1[i-1][j]*(((N[i-1]-'0')==0)?(1):(0));
    }
  }
  cout << (dp0[N.size()][K]+dp1[N.size()][K]);
  return 0;
}
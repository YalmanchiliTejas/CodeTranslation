#include <bits/stdc++.h>
using namespace std;
int dp[100][2][5];

int main(){
  string N;
  int K;
  vector<int> n;
  cin >> N >> K;
  int l = N.size();
  for(auto a : N) n.push_back(a-'0');
  
  dp[0][0][0]=1;
  dp[0][1][0]=0;
  dp[0][0][1]=0;
  dp[0][1][1]=0;
  for(int i=0; i<l; i++){
    for(int smaller=0; smaller<2; smaller++){
      for(int j=0; j<5; j++){
        for(int x=0; x <= (smaller ? 9 : n[i]); x++){
          dp[i+1][smaller || x<n[i]][x!=0 ? min(4, j+1) : j]+=dp[i][smaller][j];
        }
      }
    }
  }
  cout << dp[l][0][K]+dp[l][1][K] << endl;
}
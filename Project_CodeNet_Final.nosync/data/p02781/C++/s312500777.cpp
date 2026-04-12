#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  vector<int> v;
  while(cin.peek() != '\n')v.push_back(getchar()-'0');
  int n = (int)v.size();
  int k; cin >> k;
  ll dp1[101][5] = {};
  ll dp2[101][5] = {};
  dp1[0][1] = v[0]-1;
  dp1[0][0] = 1;
  dp2[0][1] = 1;
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j <= k; ++j){
      dp1[i+1][j] += dp1[i][j]+dp2[i][j]*(v[i+1]!=0);
      dp1[i+1][j+1] += dp1[i][j]*9+dp2[i][j]*max<ll>(v[i+1]-1,0);
      dp2[i+1][j] += dp2[i][j]*(v[i+1]==0);
      dp2[i+1][j+1] += dp2[i][j]*(v[i+1]!=0);
    }
  }
  cout << dp1[n-1][k] + dp2[n-1][k] << endl;
}
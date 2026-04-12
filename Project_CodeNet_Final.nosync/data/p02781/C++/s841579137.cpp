#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  int n = s.size();
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(K+1, vector<int>(2, 0)));

  dp.at(0).at(0).at(0) = 1;
  rep(i, n)rep(j, K+1)rep(k, 2){
    rep(m, 10){
      int ni = i+1, nj = j, nk = k;
      if(m != 0)nj++;
      if(nj > K) continue;
      if(nk == 0){
        if(m < (s.at(i) - '0')) nk = 1;
        if(m > (s.at(i) - '0'))continue;
      }
      // if(dp.at(i).at(j).at(k) == 1){
      //   cout << "tt:" << ni << " " << nj << " " << nk << " " << m << endl;
      // }
      dp.at(ni).at(nj).at(nk) += dp.at(i).at(j).at(k);
    }
  }
  
  // rep(i, n+1){
  //   rep(j, K+1){
  //     cout << dp.at(i).at(j).at(0) << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // rep(i, n+1){
  //   rep(j, K+1){
  //     cout << dp.at(i).at(j).at(1) << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  int ans = dp.at(n).at(K).at(0) + dp.at(n).at(K).at(1);
  cout << ans << endl;
  return 0;
}
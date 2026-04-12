#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
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
  vector<vector<vector<ll>>> dp(s.size()+1, vector<vector<ll>>(K+1, vector<ll>(2, 0)));
  dp.at(0).at(0).at(0) = 1;
  rep(i, s.size())rep(j, K+1)rep(k, 2){
    int ni = i+1;
    int now = s.at(i) - '0';
    rep(m, 10){
      int nj = j, nk = k;
      if(k == 0){
        if(m > now) break;
        if(m < now) nk++;
      }
      if(m != 0) nj++;
      if(nj > K) continue;
      dp.at(ni).at(nj).at(nk) += dp.at(i).at(j).at(k);
    }
  }
  // rep(j, K+1){
  //   rep(i, s.size()+1){
  //     cerr << dp.at(i).at(j).at(0) << " ";
  //   }
  //   cerr << endl;
  // }
  // rep(j, K+1){
  //   rep(i, s.size()+1){
  //     cerr << dp.at(i).at(j).at(1) << " ";
  //   }
  //   cerr << endl;
  // }
  cout << dp.at(s.size()).at(K).at(0) + dp.at(s.size()).at(K).at(1) << endl;
  return 0;
}
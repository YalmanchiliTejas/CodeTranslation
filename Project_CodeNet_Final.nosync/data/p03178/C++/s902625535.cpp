#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  string k;
  int d;
  cin >> k;
  cin >> d;
  vector<vector<vector<ll>>> dp(k.size()+1,vector<vector<ll>>(d,vector<ll>(2,0)));
  dp[0][0][0] = 1;
  for(int i=1;i<=k.size();i++){
    int kd = k.at(i-1) -'0';
    for(int j=0;j<d;j++){
      rep(g,10){
        int ch = (j-g+g*d)%d ;
        //cout << ch << endl;
        if(kd > g){
          dp.at(i).at(j).at(1) = (dp.at(i).at(j).at(1) + dp.at(i-1).at(ch).at(0))%MOD;
        }else if(kd == g){
          dp.at(i).at(j).at(0) = (dp.at(i).at(j).at(0) + dp.at(i-1).at(ch).at(0))%MOD;
        }
        dp.at(i).at(j).at(1) = (dp.at(i).at(j).at(1) + dp.at(i-1).at(ch).at(1))%MOD;
      }
    }
  }
  ll ans = (dp.at(k.size()).at(0).at(0) + dp.at(k.size()).at(0).at(1) - 1 + MOD) %MOD;
  cout << ans << endl;

  return 0;
}


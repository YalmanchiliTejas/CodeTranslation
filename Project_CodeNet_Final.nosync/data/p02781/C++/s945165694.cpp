#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
int first = 0;
vector<int> pp;

int len(string n){
  int c = n.size();
  rep(i,c){
    pp.push_back(n.at(i)-'0');
  }
  first = pp[0];
  return c;
} 
  
 
int main() {
  int k;
  string n;
  cin >> n >> k;
  int c = len(n);
  vector<vector<vector<ll>>> dp(c,vector<vector<ll>>(4,vector<ll>(2,0)));
  dp.at(0).at(0).at(0) = 0;
  dp.at(0).at(0).at(1) = 1; 
  dp.at(0).at(1).at(0) = 1;
  dp.at(0).at(1).at(1) = first-1;
  for(int i=1;i<c;i++)for(int j=0;j<4;j++)rep(k,2){
    if(j==0 && k==1){
      dp.at(i).at(j).at(k) = 1;continue;
    }else if(j==0 && k==0) {
      dp.at(i).at(j).at(k) = 0;continue;
    }
    if(k==0){
      if(pp.at(i)==0){
        dp.at(i).at(j).at(k) = dp.at(i-1).at(j).at(k);
      }else{
        dp.at(i).at(j).at(k) = dp.at(i-1).at(j-1).at(k);
      }
    }else{
      dp.at(i).at(j).at(k) = dp.at(i-1).at(j).at(k)+dp.at(i-1).at(j-1).at(k)*9;
      if(pp.at(i)!=0){
        dp.at(i).at(j).at(k) += dp.at(i-1).at(j-1).at(k-1)*(pp.at(i)-1) + dp.at(i-1).at(j).at(k-1);
      }
    }
  }
  ll ans = 0;
  if(k==0) cout << ans << endl;
  else{
  rep(j,2){
   ans += dp.at(c-1).at(k).at(j);
  }
  cout << ans << endl;
  } 
  /*rep(i,pp.size()) cout << pp.at(i) << " ";
  rep(i,c){
    rep(j,4){
      rep(k,2) cout << dp.at(i).at(j).at(k) << " ";
    cout << endl;
    }
    cout << endl;
  }*/
    
    
                                 
  return 0;
}


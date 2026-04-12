#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;
ll dp[105][2][5];
int main(){
  string n; cin >> n;
  ll k; cin >> k;
  dp[0][0][0]=1;
  rep(i,n.size()){
    ll u = (ll)(n[i]-'0');
    rep(smaller,2){
      rep(j,4){
        for(ll p=0;p<=(smaller ? 9 : u);p++){
          ll q = dp[i][smaller][j];
          if(debug){
            cout << i << " " << smaller << " " << j << "=>" << q << endl;
          }
          dp[i+1][smaller||p<u][(p==0?j:j+1)]+=dp[i][smaller][j];
        } 
      }
    }
  }
  if(debug){
    cout << dp[n.size()][0][k] << endl;
    cout << dp[n.size()][1][k] << endl;
  }
  cout << dp[n.size()][0][k]+dp[n.size()][1][k] << endl;
  return 0;
}
//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=5e18;
typedef pair<int,int> P;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int d;
  string s;
  cin >> s >> d;
  ll ans=0,dp[10005][2][105]={};
  cin >> s >> d;
  dp[0][0][0]=1;
  for(int i=0; i<s.size(); i++) {
    for(int j=0; j<2; j++) {
      for(int k=0; k<d; k++) {
        int lim=j?9:s[i]-'0';
        for(int l=0; l<=lim; l++) {
          (dp[i+1][j||l<lim][(k+l)%d]+=dp[i][j][k])%=MOD;
        }
      }
    }
  }
  for(int i=0; i<2; i++) {
    ans+=dp[s.size()][i][0];
    ans%=MOD;
  }
  ans--;
  if(ans<0) {
    ans+=MOD;
  }
  cout << ans << "\n";
}
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
  string s;
  int k,dp[105][2][105]={},ans=0;
  cin >> s >> k;
  dp[0][0][0]=1;
  for(int i=0; i<s.size(); i++) {
    for(int j=0; j<2; j++) {
      for(int l=0; l<105; l++) {
        int lim=j?9:s[i]-'0';
        for(int m=0; m<=lim; m++) {
          dp[i+1][j||m<lim][l+(m!=0)]+=dp[i][j][l];
        }
      }
    }
  }
  for(int i=0; i<2; i++) {
    ans+=dp[s.size()][i][k];
  }
  cout << ans << "\n";
}

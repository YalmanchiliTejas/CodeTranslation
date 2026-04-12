//解説見ました.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll dp[105][4][2];

int main(){
  string s;
  cin >>s;
  ll n = s.size();
  ll hi;
  cin >> hi;
  dp[0][0][0]=1;
  for(int i=0; i<n; i++){
   for(int j=0; j<4; j++){
    for(int k=0; k<2; k++){
      ll nd = s[i]-'0';
      for(int d=0; d<10; d++){
        int ni=i+1,nj=j,nk=k;
        if(d!=0)nj++;
        if(nj>hi)continue;
        if(k==0){
          if(d>nd)continue;
          if(d<nd)nk=1;
        }
        dp[ni][nj][nk] += dp[i][j][k];
      }
    }
   }
  }
  
  ll ans = dp[n][hi][0] + dp[n][hi][1];
  cout << ans << endl;
  return 0;
}
  
  
  

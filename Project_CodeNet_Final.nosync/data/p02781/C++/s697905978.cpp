#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string n;
  ll k;
  cin >> n >> k;
  vector<vector<ll>> dp0(n.size()+1,vector<ll>(k+1,0));
  vector<vector<ll>> dp1(n.size()+1,vector<ll>(k+1,0));
  dp1[0][0]=1;
  dp0[0][0]=0;
  for(ll i=0;i<n.size();i++) {
    for(ll j=0;j<=k;j++) {
      dp0[i+1][j]+=dp0[i][j];
      if(j<k) {
        dp0[i+1][j+1]+=dp0[i][j]*9;
        if(n[i]!='0') {
          dp0[i+1][j+1]+=dp1[i][j]*(int(n[i]-'0')-1);
        }
      }
      if(n[i]!='0'){
        if(j<k){
          dp1[i+1][j+1]+=dp1[i][j];
        }
        dp0[i+1][j]+=dp1[i][j];
      }
      else {
        dp1[i+1][j]+=dp1[i][j];
      }
    }
  }
  cout << dp0[n.size()][k] + dp1[n.size()][k] << endl;
}
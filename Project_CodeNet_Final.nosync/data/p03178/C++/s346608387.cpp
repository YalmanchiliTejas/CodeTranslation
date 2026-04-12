#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;
 
int main() {
  string s;
  ll d;
  cin >> s >> d;
  ll k=s.size();
  mat dp0(k+1,vec(d));
  mat dp1(k+1,vec(d));
  dp0[0][0]=1;
  for(ll i=0;i<k;i++) {
    for(ll j=0;j<d;j++) {
      ll nj0=(j+(s[i]-'0'))%d;
      (dp0[i+1][nj0]+=dp0[i][j])%=mod;
      for(ll n=0;n<=9;n++) {
        ll nj=(j+n)%d;
        if(n<(s[i]-'0')) {
          (dp1[i+1][nj]+=dp0[i][j])%=mod;
        }
        (dp1[i+1][nj]+=dp1[i][j])%=mod;
      }
    }
  }
  cout << (dp0[k][0]+dp1[k][0]-1+mod)%mod << endl;
}
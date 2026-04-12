#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  string s;
  ll d;
  cin >> s >> d;
  ll n=s.size();
  mat dp0(n+1,vec(d)),dp1(n+1,vec(d));
  dp0[0][0]=1;
  for(ll i=0;i<n;i++) {
    ll id=s[i]-'0';
    for(ll j=0;j<d;j++) {
      (dp0[i+1][(j+id)%d]+=dp0[i][j])%=mod;
      for(ll k=0;k<10;k++) {
        (dp1[i+1][(j+k)%d]+=dp1[i][j])%=mod;
        if(id>k) {
          (dp1[i+1][(j+k)%d]+=dp0[i][j])%=mod;
        }
      }
    }
  }
  cout << (dp0[n][0]+dp1[n][0]-1+mod)%mod << endl;
}
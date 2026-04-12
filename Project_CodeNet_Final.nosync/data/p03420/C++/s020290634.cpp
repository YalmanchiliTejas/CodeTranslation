#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;

int main(){
  ll n,k; cin >> n >> k;
  ll ans=0;
  ans+=(n-k)*(n-k+1)/2;
  rep(b,n){
    ll pm = n/b;
    rep(p,pm){
      ll qm = min(b-1,n-p*b);
      if(qm<k) continue;
      ans += qm-k+1;
    }
  }
  if(k==0) ans-=n;
  cout << ans;
  return 0;
}
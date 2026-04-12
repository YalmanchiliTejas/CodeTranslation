#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

int main(){
  ll N,s=0,ans=0;
  cin >> N;
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
    ans+=s*A.at(i);
    ans%=MOD;
    s+=A.at(i);
    s%=MOD;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return (ll)(-1);
}
ll d;
bool f(ll x){
  return x<d;
}

int main(){
  ll N,Q;
  cin >> N >> Q;
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
  }
  
  segtree<ll, op, e> seg(A);
  rep(i,Q){
    ll a,b,c;
    cin >> a >> b >> c;
    b--;
    if(a==1){
      seg.set(b,c);
    }else if(a==2){
      cout << seg.prod(b,c) << endl;
    }else{
      d=c;
      cout << seg.max_right<f>(b)+1 << endl;
    }
  }
}
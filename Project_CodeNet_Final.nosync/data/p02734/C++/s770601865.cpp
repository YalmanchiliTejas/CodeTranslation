#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 998244353;


int main(){
  int N, S;
  cin >> N >> S;
  vector<ll> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  vector<ll> ret(S+1,0);
  vector<ll> x(S+1,0);
  x[0] = 1;
  if(v[0]<=S) x[v[0]] = 1;
  rep(i,x.size()){
    ret[i] = x[i];
  }
  x[0] += 1;

  REP(i,1,N){
    vector<ll> y(S+1,0);
    rep(j,x.size()){
      if(j+v[i]<=S){
        y[j+v[i]] += x[j];
        y[j+v[i]] %= MOD;
      }
      y[j] += x[j];
      y[j] %= MOD;
    }
    rep(j,x.size()){
      ret[j] += y[j];
      ret[j] %= MOD;
      x[j] = y[j];
    }
    x[0] += 1;
    x[0] %= MOD;
  }

  cout << ret[S] << endl;
  
  return 0;
}

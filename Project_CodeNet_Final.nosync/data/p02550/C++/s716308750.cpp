#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


ll memo[100005];

int main(){
  ll N, X, M;
  cin >> N >> X >> M;

  if(N == 1){
    cout << X << endl;
    return 0;
  }

  rep(i,100005) memo[i] = -1;

  vector<ll> v;
  v.push_back(X);
  ll now = X;
  memo[now] = 0;
  ll ret = X;
  int idx = 2;
  bool flg = false;
  for(; idx<=N; idx++){
    now = (now*now)%M;
    if(memo[now] == -1){
      ret += now;
      memo[now] = idx-1;
      v.push_back(now);
    }else{
      flg = true;
      break;
    }
  }

  if(!flg){
    cout << ret << endl;
    return 0;
  }

  ll bgn = memo[now];
  ll end = v.size();
  ll m = end - bgn;

  vector<ll> w;
  ll s = 0;
  REP(i,bgn,end){
    s += v[i];
    w.push_back(v[i]);
  }

  ll cnta = (N+1-idx)/m;
  ll cntb = (N+1-idx)%m;
  ret += cnta * s;
  rep(i,cntb){
    ret += w[i];
  }
  
  cout << ret << endl;
  
  
  return 0;
}


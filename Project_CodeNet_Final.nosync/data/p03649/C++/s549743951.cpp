#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  ll N;
  cin >> N;
  vector<ll> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  ll ret = 0;
  bool flg = true;
  while(flg){
    flg = false;

    ll sum = 0;
    vector<ll> cnt(N, 0);
    rep(i,N){    
      cnt[i] = v[i]/N;
      v[i] -= N * cnt[i];
      sum += cnt[i];
    }
    rep(i,N){
      v[i] += sum - cnt[i];
      if(v[i] >= N) flg = true;
    }
    ret += sum;
  }

  cout << ret << endl;
  
  return 0;
}

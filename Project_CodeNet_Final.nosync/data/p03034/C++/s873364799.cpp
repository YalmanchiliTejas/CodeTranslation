#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  vector<ll> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  ll ret = 0;
  REP(C,1,N){
    ll score = 0;
    ll x = 0;
    map<int,int> m;
    bool flg = true;
    while(true){
      // range
      if(x*C >= N) break;
      if((N-1)-x*C < 0) break;
      // B > 0 <=> A-C > 0
      if((N-1)-x*C-C <= 0) break;
      // overlap
      if(m.count(x*C) > 0) break;
      m[x*C] = 1;
      if(m.count((N-1)-x*C) > 0) break;
      m[(N-1)-x*C] = 1;
      
      score += v[x*C];
      score += v[(N-1)-x*C];
      //cout << C << " " << x << " " << score << endl;
      ret = max(ret, score);
      x++;
    }
  }

  cout << ret << endl;
  
  return 0;
}


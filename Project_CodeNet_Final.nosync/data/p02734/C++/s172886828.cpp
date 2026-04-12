#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 998244353;

ll dp[3005];

int main(){
  int N, S;
  cin >> N >> S;
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }

  ll ret = 0;
  rep(i,N){
    dp[0] += 1;
    vector<ll> dp2(3005, 0);
    rep(j,S+1){
      dp2[j] += dp[j];
      dp2[j] %= MOD;
      if(j+v[i] <= S){
        dp2[j+v[i]] += dp[j];
        dp2[j+v[i]] %= MOD;
      }
    }
    rep(j,3005) dp[j] = dp2[j];

    ret += dp[S];
    ret %= MOD;
  }

  cout << ret << endl;
  
  return 0;
}


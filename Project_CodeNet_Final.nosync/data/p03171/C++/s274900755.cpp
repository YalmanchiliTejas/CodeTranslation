#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORALL(i, m) for( auto i = m.begin(); i != m.end() ; ++i )
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define TM_T template <class T>
using namespace std;
typedef long long ll;
TM_T T inp(){T it;cin >> it;return it;}

ll N;
vector<ll> li;
vector<vector<ll>> dp;

int input(){
  cin >> N;
  REP(i,N) li.push_back( inp<ll>() );
}

int main()
{
  input();
  
  REP(i,N){
    dp.push_back( vector<ll>() );
    REP(j,N) dp[i].push_back( -1000000000000000l );
  }
  REP(i,N) dp[i][N-1-i] = li[i];
  REPR(i,N-2){
    REP(j,i+1){
      ll ma = -1000000000000000l;
      ma = max(ma, li[j] - dp[j+1][i-j]);
      ma = max(ma, li[N-1-(i-j)]- dp[j][i-j+1]);
      dp[j][i-j] = ma;
    }
  }
  cout << dp[0][0] << endl;
}
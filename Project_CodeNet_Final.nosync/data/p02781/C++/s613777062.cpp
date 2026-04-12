#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;
ll K,dp[10010][110][2]; // dp[桁][余り][Nとぴったりか] := 総数
string N;

void compute() {
  reverse(N.begin(),N.end());
  dp[(int)N.size()][0][1] = 1LL;
  for(int i=(int)N.size();i>=1;i--) {
    for(ll remain=0;remain<K+1;remain++) {
        rep(sameN,2) {
          rep(digit, 10) {
            int new_remain = remain + (digit != 0);//(N[i-1] - '0' != 0);
            if( sameN && digit > (N[i-1] - '0')) continue;
            int new_sameN = sameN;
            if( sameN && digit < ( N[i-1] - '0' ) ) new_sameN = 0;
            ( dp[i-1][new_remain][new_sameN] += dp[i][remain][sameN] ) %= mod;
          }
      }
    }
  }
  cout << ( dp[0][K][0] + dp[0][K][1] + mod ) % mod << endl;
}

int main() {
  cin >> N >> K;
  compute();
  return 0;
}
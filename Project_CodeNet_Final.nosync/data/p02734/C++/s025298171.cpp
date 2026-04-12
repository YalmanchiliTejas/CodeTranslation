//#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//#include <queue>
//#include <stack>
#include <cstring>
#include <cassert>

using namespace std;

#ifdef LOCAL_DEBUG
#include <local_debug.h>
#define DEBUG(...) DBG2::print(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int MOD = 998244353;

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(nullptr);

   int N, S;
   cin >> N >> S;
   VI A(N+1);
   FOR(i, 1, N)
      cin >> A[i];

   int res = 0;

   VVI DP(N+1, VI(S+1));
   DP[0][0] = 1;
   FOR(n, 1, N) {
      DP[n][0] = n+1;
      FOR(s, 1, S-1) {
         DP[n][s] = DP[n-1][s];
         if (s-A[n] >= 0) {
            DP[n][s] += DP[n-1][s-A[n]];
            if (DP[n][s] >= MOD)
               DP[n][s] -= MOD;
         }
      }
      if (S-A[n] >= 0) {
         res = (res + DP[n-1][S-A[n]] * 1LL * (N-n+1)) % MOD;
      }
   }
   
   /*
   FOR(n, 0, N) {
      FOR(s, 0, S) {
         cerr << DP[n][s] << ' ';
      }
      cerr << endl;
   }
   */

   cout << res << '\n';

   return 0;
}

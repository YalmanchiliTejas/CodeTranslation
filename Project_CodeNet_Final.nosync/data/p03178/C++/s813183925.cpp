//#include <cstdio>
#include <iostream>

#include <cstring>

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//#include <queue>
//#include <stack>
#include <cassert>

using namespace std;

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int MOD = 1e9 + 7;

string K;
int D;

int memo[10001][2][101];
int go(int n = 0, bool lt = false, int rem = 0) {
   if (n >= SZ(K))
      return rem == 0 ? 1 : 0;
   int& res = memo[n][lt][rem];
   if (res < 0) {
      res = 0;
      FOR(d, 0, lt ? 9 : K[n]-'0') {
         res += go(n+1, lt || (d < K[n]-'0'), (rem + d) % D);
         if (res >= MOD)
            res -= MOD;
      }
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(nullptr);

   cin >> K;
   cin >> D;

   memset(memo, -1, sizeof(memo));
   int res = go() - 1;  // substract one due to 0
   if (res < 0)
      res += MOD;
   cout << res << '\n';

   return 0;
}

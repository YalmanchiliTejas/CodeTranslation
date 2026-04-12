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

const int MOD = 1e9 + 7;

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(nullptr);

   int N;
   cin >> N;
   VI A(N);
   REP(i, N)
      cin >> A[i];

   llong res = 0;
   llong sum = 0;
   REP(j, N) {
      res = (res + (A[j] * sum) % MOD) % MOD;
      sum = (sum + A[j]) % MOD;
   }
   cout << res << endl;

   return 0;
}

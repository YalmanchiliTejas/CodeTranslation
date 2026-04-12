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

#define MAXN 3004
int N;
int A[MAXN];
llong PS[MAXN];
llong sum(int L, int R) {
   return PS[R] - PS[L-1];
}

llong memo[MAXN][MAXN];
llong go(int L, int R) {
   if (L > R) return 0;
   llong& res = memo[L][R];
   if (res < 0) {
      res = sum(L, R)-min(go(L+1, R), go(L, R-1));
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(nullptr);

   cin >> N;
   FOR(i, 1, N)
      cin >> A[i];

   FOR(i, 1, N)
      PS[i] = PS[i-1] + A[i];

   memset(memo, -1, sizeof(memo));
   llong first = go(1, N);
   llong second = sum(1, N) - first;
   cout << first - second << '\n';

   return 0;
}

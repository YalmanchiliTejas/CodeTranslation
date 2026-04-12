#include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

LL powe(LL a, LL b) {
  LL r = 1;
  while (b) {
    if (b&1) {
      (r *= a) %= MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return r;
}

int H[105];
// ababababab..., any
pair<LL, LL> go(int a, int b, int offset) {
  // printf("%d %d %d\n", a, b, offset);

  if (a == b) return { 1, 1 };

  int mini = 1e9;
  FOR(i,a,b) mini = min(mini, H[i] - offset);
  if (mini == 0) return {1, 1};
  // assert(mini > 0);

  if (a + 1 == b) return { powe(2, mini-1), powe(2, mini) };

  int S = a;

  LL aba = 1, any = 1, aba_counted = 1;
  int minis = 0;
  FOR(i,a,b+1) {
    if (i == b || H[i]-offset == mini) {
      if (i > S) {
        auto rec = go(S, i, offset+mini);

        (aba *= 2 * rec.st) %= MOD;
        (any *= (rec.nd + 2 * rec.st)) %= MOD;
      }

      S = i + 1;

      if (i < b) {
        (any *= 2) %= MOD;
        ++minis;
      }
    }
  }

  // printf("%d %d %d %lld %lld(%d %lld)\n", a, b, offset, aba, any, mini, powe(2, mini)-2);
  (any += 2 * aba * (powe(2, mini-1)-1)) %= MOD;
  (aba *= powe(2, mini-1)) %= MOD;
  // printf("%d %d %d %lld %lld\n", a, b, offset, aba, any);

  return {aba, any};
}

int main() {
  // ios_base::sync_with_stdio(0);

  int N;
  scanf("%d", &N);
  REP(i,N) {
    scanf("%d", &H[i]);
  }

  LL any = 0;
  REP(i,N) {
    int h = 0;
    if (i > 0) h = max(h, H[i-1]);
    if (i < N-1) h = max(h, H[i+1]);
    h = min(h, H[i]);
    any += H[i] - h;
    H[i] = h;
  }

  LL result = powe(2, any);
  auto r = go(0, N, 0);
  (result *= r.nd) %= MOD;

  /*
  REP(i,N) {
    if (H[i] == 1) {
      ++any;
      (result *= go(S,i)) %= MOD;
      S = i + 1;
    }
  }

  (result *= powe(2, any)) %= MOD;
  */

  printf("%lld\n", result);
}

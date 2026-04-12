#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

LL patty(int level) {
  LL res = 1;
  for (int i=0; i<level; ++i) {
    res = 2*res + 1;
  }
  return res;
}

LL count(LL ind, int level) {
  if (level==0) return 1;
  LL thkness = 1;
  for (int i=0; i < level; ++i) {
    thkness = 2*thkness + 3;
  }

  if (ind == 0) return 0;
  if (ind == thkness - 1) return patty(level);
  if (ind > (thkness-1)/2) {
    return patty(level-1) + count(ind - (thkness-1)/2 - 1, level-1) + 1;
  } else if (ind == (thkness-1)/2) {
    return patty(level-1) + 1;
  } else {
    return count(ind-1, level-1);
  }
}

int main() {
  LL N, X;
  cin >> N >> X;
  X -= 1;

  cout << count(X, N) << endl;

  return 0;
}
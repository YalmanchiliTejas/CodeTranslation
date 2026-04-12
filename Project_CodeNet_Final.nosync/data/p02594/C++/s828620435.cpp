#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

const string YES = "Yes";
const string NO = "No";

void solve(long long X) {
  cout << (X >= 30 ? YES : NO) << endl;
}

int main() {
  long long X;
  scanf("%lld", &X);
  solve(X);
  return 0;
}

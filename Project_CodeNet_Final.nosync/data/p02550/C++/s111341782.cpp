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

bool done[100005];

void solve(long long N, long long X, long long M) {
  done[X] = true;
  ll a = X;
  ll i = 1;
  ll ans = a;
  vector<ll> v;
  v.push_back(a);
  while (i < N) {
    a = (a * a) % M;
    if (done[a]) {
      break;
    }
    v.push_back(a);
    ans += a;
    done[a] = true;
    i++;
  }
  if (i == N) {
    cout << ans << endl;
    return;
  }
  if (a == 0) {
    cout << ans << endl;
    return;
  }
  ll j = 0;
  while (v[j] != a) {
    j++;
  }
  ll y = (N - i) / (v.size() - j);
  ll sum = 0;
  FOR(k, j, v.size()) {
    sum += v[k];
  }
  ans += sum * y;
  ll z = (N - i) % (v.size() - j);
  FOR(k, j, j + z) {
    ans += v[k];
  }
  cout << ans << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long X;
  scanf("%lld", &X);
  long long M;
  scanf("%lld", &M);
  solve(N, X, M);
  return 0;
}

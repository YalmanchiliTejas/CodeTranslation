#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                         \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z     \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

void solve(ll N, ll M, std::vector<ll> a, std::vector<ll> b) {
  vector<ll> e(N);
  for (int i = 0; i < N; i++) {
    e.at(i) = i;
  }

  ll count = 0;

  do {
    if (e.at(0) == 0) {
      bool result = true;
      rep(i, N - 1) {
        bool found = false;
        rep(j, M) {
          if ((e.at(i) == a.at(j) && e.at(i + 1) == b.at(j)) ||
              (e.at(i + 1) == a.at(j) && e.at(i) == b.at(j))) {
            found = true;
            break;
          }
        }
        result = result && found;
        if (!result)
          break;
      }

      if (result)
        count++;
    }
  } while (next_permutation(all(e)));

  cout << count << endl;
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll M;
  scanf("%lld", &M);
  std::vector<ll> a(M);
  std::vector<ll> b(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
    a[i]--;
    b[i]--;
  }
  solve(N, M, std::move(a), std::move(b));
  return 0;
}

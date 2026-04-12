#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

typedef long long ll;

const int N_MAX = 200000;

typedef pair<int, int> P;

int N;
int x[N_MAX];
int y[N_MAX];
P p[N_MAX];
int z[N_MAX * 2];
multiset<int> bs;

void erase_one(multiset<int> &st, int v) {
  auto it = st.find(v);
  if (it != st.end()) st.erase(it);
}

void solve() {
  REP(i, N) {
    int zi = min(x[i], y[i]);
    int zx = max(x[i], y[i]);
    p[i] = { zi, zx };
    z[i] = zi;
    z[N + i] = zx;
  }
  sort(p, p + N);
  sort(z, z + N * 2);
  int zx = z[N * 2 - 1];
  int zi = z[0];
  // printf("(1) zx: %d, zi: %d\n", zx, zi);

  int rx = zx, ri = zx, bx = zi, bi = zi;
  REP(i, N) {
    ri = min(ri, p[i].second);
    bx = max(bx, p[i].first);
  }
  ll ans1 = (ll) (rx - ri) * (bx - bi);
  // printf("(2) rx: %d, ri: %d, bx: %d, bi: %d, ans1: %lld\n", rx, ri, bx, bi, ans1);

  rx = zx; ri = zi;
  REP(i, N) bs.insert(p[i].first);
  REP(i, N) {
    int bw = *bs.rbegin() - *bs.begin();
    erase_one(bs, p[i].first);
    bs.insert(p[i].second);
    if (*bs.rbegin() - *bs.begin() > bw) {
      erase_one(bs, p[i].second);
      bs.insert(p[i].first);
    }
  }
  bx = *bs.rbegin(), bi = *bs.begin();
  ll ans2 = (ll) (rx - ri) * (bx - bi);
  // printf("(3) rx: %d, ri: %d, bx: %d, bi: %d, ans2: %lld\n", rx, ri, bx, bi, ans2);

  printf("%lld\n", min(ans1, ans2));
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", x + i, y + i);
}

int main() {
  input();
  solve();
  return 0;
}

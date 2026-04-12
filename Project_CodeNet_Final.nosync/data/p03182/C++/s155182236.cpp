#include <iostream>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <vector>

int const MAXN = 200000;
int const MAXM = 200000;
uint64_t const INF = 1<<59;

int const MAXA = (1<<19)-1;

int N, M, NN;

int64_t dp[MAXA], lazy[MAXA];
std::vector<std::pair<int, int> > scores[MAXM];

void init() {
  NN=1;
  while(NN<N+2) NN<<=1;
  std::fill(dp, dp+NN*2-1, 0);
  std::fill(lazy, lazy+NN*2-1, 0);
}

void eval(int k) {
  if(lazy[k] == 0) return;
  if(k*2+1 < NN*2-1) {
    lazy[2*k+1] += lazy[k];
    lazy[2*k+2] += lazy[k];
  }
  dp[k] += lazy[k];
  lazy[k] = 0;
}

int64_t update(int a, int b, int64_t x, int k, int l, int r) {
  if(b <= l || r <= a) {
    eval(k);
    return dp[k];
  }
  if(a <= l && r <= b) {
    lazy[k] += x;
    return dp[k] + lazy[k];
  }
  eval(k);
  int m = (l+r)/2;
  return dp[k] = std::max(update(a, b, x, k*2+1, l, m), update(a, b, x, k*2+2, m, r));
}

int64_t query(int a, int b, int k, int l, int r) {
  if(b <= l || r <= a) return -INF;
  eval(k);
  if(a <= l && r <= b) return dp[k];
  int m = (l+r)/2;
  bool intLeft = !(m <= a || b <= l);
  bool intRight = !(r <= a || b <= m);
  if(intLeft&intRight) return std::max(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
  if(intLeft) return query(a, b, k*2+1, l, m);
  return query(a, b, k*2+2, m, r);
}

void add(int a, int b, int64_t x) { update(a, b, x, 0, 0, NN); }
int64_t get_max(int a, int b) { return query(a, b, 0, 0, NN); }

int main() {
  std::cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int l, r, a;
    std::cin >> l >> r >> a; --l; --r;
    scores[r].emplace_back(l, a);
  }

  init();
  for(int i = 0; i < N; ++i) {
    int64_t m = 0;
    if(i > 0) m = std::max(m, get_max(0, i));
    add(i, i+1, m);
    for(auto p: scores[i]) add(p.first, i+1, p.second);
  }
  int64_t m = 0;
  std::cout << std::max(get_max(0, N+1), m) << std::endl;
  return 0;
}

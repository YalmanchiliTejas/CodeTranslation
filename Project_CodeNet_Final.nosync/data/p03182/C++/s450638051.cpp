#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

const int MaxN = 200000 + 5, MaxM = 200000 + 5;

int N, M;
std::map<int, long long> Mp[MaxN];

struct SegTree {
  int L[MaxN * 4], R[MaxN * 4];
  long long Max[MaxN * 4], Tag[MaxN * 4];

  void pushDown(int i) {
    if (Tag[i] != 0) {
      int ls = i << 1, rs = i << 1 | 1;
      Max[ls] += Tag[i];
      Max[rs] += Tag[i];
      Tag[ls] += Tag[i];
      Tag[rs] += Tag[i];
      Tag[i] = 0;
    }
  }

  void buildTree(int left, int right, int i) {
    L[i] = left, R[i] = right;
    if (L[i] == R[i]) return;
    int mid = (L[i] + R[i]) >> 1;
    buildTree(left, mid, i << 1);
    buildTree(mid + 1, right, i << 1 | 1);
  }

  void updateTree(int left, int right, long long val, int i) {
    if (L[i] == left && R[i] == right) {
      Tag[i] += val;
      Max[i] += val;
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) updateTree(left, right, val, i << 1);
    else if (left > mid) updateTree(left, right, val, i << 1 | 1);
    else updateTree(left, mid, val, i << 1), updateTree(mid + 1, right, val, i << 1 | 1);
    Max[i] = std::max(Max[i << 1], Max[i << 1 | 1]);
  }

  void updateTree(int pos, long long val, int i) {
    if (L[i] == R[i]) {
      Max[i] = std::max(Max[i], val);
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (pos <= mid) updateTree(pos, val, i << 1);
    else updateTree(pos, val, i << 1 | 1);
    Max[i] = std::max(Max[i << 1], Max[i << 1 | 1]);
  }

  long long queryTree(int left, int right, int i) {
    if (L[i] == left && R[i] == right) return Max[i];
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) return queryTree(left, right, i << 1);
    else if (left > mid) return queryTree(left, right, i << 1 | 1);
    else return std::max(queryTree(left, mid, i << 1), queryTree(mid + 1, right, i << 1 | 1));
  }
};
SegTree T;

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    Mp[r][l] += a;
  }
}

void solve() {
  T.buildTree(0, N, 1);
  for (int r = 1, preR = 0; r <= N; ++r) {
    bool fir = true;
    for (auto p : Mp[r]) {
      int l = p.first; long long a = p.second;
      if (fir == true) {
        for (int i = preR + 1; i <= r; ++i)
          T.updateTree(i, T.queryTree(0, r - 1, 1), 1);
        preR = r;
      }
      fir = false;
      T.updateTree(l, r, a, 1);
//      printf("l = %d, r = %d, a = %lld\n", l, r, a);
//      for (int i = 0; i <= N; ++i)
//        printf("F[%d] = %lld\n", i, T.queryTree(i, i, 1));
    }
  }
  printf("%lld\n", T.queryTree(0, N, 1));
}

int main() {
  init();
  solve();
  return 0;
}

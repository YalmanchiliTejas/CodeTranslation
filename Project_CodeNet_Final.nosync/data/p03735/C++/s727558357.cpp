#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 200005, INF = 0x3f3f3f3f;
typedef long long i64;

int N, A[MAX_N], B[MAX_N];

i64 work1() {
  int Rmin = INF, Rmax = -INF, Bmin = INF, Bmax = -INF;
  for (int i = 1; i <= N; ++i) {
    Rmin = min(Rmin, A[i]), Rmax = max(Rmax, A[i]);
    Bmin = min(Bmin, B[i]), Bmax = max(Bmax, B[i]);
  }
  return 1LL * (Rmax - Rmin) * (Bmax - Bmin);
}

bool cmp(int x, int y) {
  return B[x] < B[y];
}

i64 work2() {
  int maxA = -INF, idA = 0;
  int minB = INF, idB = 0;

  for (int i = 1; i <= N; ++i) {
    if (maxA <= A[i]) maxA = A[i], idA = i;
    if (minB >= B[i]) minB = B[i], idB = i;
  }
  
  if (idA == idB) return 1LL * INF * INF;

  int temp = maxA - minB;
  int Bmin = INF, Bmax = -INF, lim = INF;
  
  static int id[MAX_N], tot;
  
  for (int i = 1; i <= N; ++i)
    if (i != idA && i != idB) {
      Bmax = max(Bmax, B[i]), lim = min(lim, A[i]);
      Bmin = min(Bmin, B[i]);
      id[++tot] = i;
    }
  
  Bmax = max(Bmax, max(B[idA], A[idB]));
  Bmin = min(Bmin, min(B[idA], A[idB]));
  i64 now = 1LL * temp * (Bmax - Bmin);
  
  sort(id + 1, id + tot + 1, cmp);

  for (int i = 2; i <= tot; ++i) {
    int x = B[id[i]], val = min(x, lim);
    Bmax = max(A[id[i - 1]], Bmax), Bmin = val;
    
    Bmin = min(Bmin, min(B[idA], A[idB]));

    now = min(now, 1LL * temp * (Bmax - Bmin));
    if (x >= lim) break;
  }

  return now;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d", &A[i], &B[i]);
    if (A[i] < B[i]) swap(A[i], B[i]);
  }

  i64 res = min(work1(), work2());

  printf("%lld\n", res);
  
  return 0;
}

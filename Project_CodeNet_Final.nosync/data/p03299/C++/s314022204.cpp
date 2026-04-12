#include <cstdio>
#include <cstring>
#include <algorithm>

#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define FILLA(a, x) memset((a), (x), sizeof (a))
#define COPYA(a, b) memcpy((b), (a), sizeof (a))

using namespace std;

typedef long long li;
typedef unsigned long long lu;
const li infl = ~0LLU >> 2;

template <class T>
inline void Min(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
inline void Max(T &x, T y) {
  if (y > x) x = y;
}

const int mod = 1e9 + 7;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
inline int Mul(int x, int y) { return (int)((li)x * y % mod); }
inline int Mul(int x, int y, int z) { return Mul(x, Mul(y, z)); }
int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}
int Inv(int x) {
  return Pow(x, mod - 2);
}

// ----------------------------------------

const int S = 8;
const lu mods = 8LLU * mod * mod;
typedef int Mat[S][S];

void MatMul(Mat a, const Mat b) {
  static lu c[S][S];
  FILLA(c, 0);
  for (int i = 0; i < S; ++i) {
    for (int k = 0; k < S; ++k) {
      for (int j = 0; j < S; ++j) {
        c[i][j] += (lu)a[i][k] * b[k][j];
        if (c[i][j] >= mods) c[i][j] -= mods;
      }
    }
  }
  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      a[i][j] = (int)(c[i][j] % mod);
    }
  }
}

void MatPow(Mat a, int e) {
  static Mat b;
  FILLA(b, 0);
  for (int i = 0; i < S; ++i) {
    b[i][i] = 1;
  }
  for (; e; e >>= 1) {
    if (e & 1) MatMul(b, a);
    MatMul(a, a);
  }
  COPYA(b, a);
}

Mat tran, tr;

int State(int L, int R, int T) {
  return L | R << 1 | T << 2;
}

void BuildTran(void) {
  FILLA(tran, 0);
  for (int L = 0; L <= 1; ++L) {
    for (int R = 0; R <= 1; ++R) {
      tran[State(L, R, 0)][State(!L, !R, 0)] = 1;
      tran[State(L, R, 1)][State(!L, !R, 1)] = 1;
      tran[State(L, R, 1)][State(L, R, 1)] = 1;
    }
  }
}

struct Part {
  int val[S];

  int & operator [] (int i) {
    return val[i];
  }

  void Tran(int h) {
    COPYA(tran, tr);
    MatPow(tr, h);
    static lu valnew[S];
    FILLA(valnew, 0);
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        valnew[j] += (lu)val[i] * tr[i][j];
        if (valnew[j] >= mods) valnew[j] -= mods;
      }
    }
    for (int i = 0; i < S; ++i) {
      val[i] = (int)(valnew[i] % mod);
    }
  }

  Part Combine(const Part &rhs) const {
    Part ans;
    FILLA(ans.val, 0);
    for (int L1 = 0; L1 <= 1; ++L1) {
      for (int R1 = 0; R1 <= 1; ++R1) {
        for (int L2 = 0; L2 <= 1; ++L2) {
          for (int R2 = 0; R2 <= 1; ++R2) {
            for (int T1 = 0; T1 <= 1; ++T1) {
              for (int T2 = 0; T2 <= 1; ++T2) {
                int Tnew = T1 && T2 && (R1 != L2);
                Add(ans.val[State(L1, R2, Tnew)],
                    Mul(val[State(L1, R1, T1)],
                        rhs.val[State(L2, R2, T2)]));
              }
            }
          }
        }
      }
    }
    return ans;
  }
};

Part SingleUnit(void) {
  Part ans;
  FILLA(ans.val, 0);
  ans[State(0, 0, 1)] = ans[State(1, 1, 1)] = 1;
  return ans;
}

// ----------------------------------------

const int maxn = 100;
const int inf = ~0U >> 1;

int n, h[maxn];

Part Solve(int l, int r, int d) {
  int min_val = inf, min_pos = -1;
  for (int i = l; i < r; ++i) {
    if (h[i] < min_val) {
      min_val = h[i];
      min_pos = i;
    }
  }

  int mid = min_pos, level = min_val - 1;
  Part ans = SingleUnit();
  if (mid > l) {
    ans = Solve(l, mid, level).Combine(ans);
  }
  if (mid < r - 1) {
    ans = ans.Combine(Solve(mid + 1, r, level));
  }
  ans.Tran(level - d);

  return ans;
}

int main(void) {
  BuildTran();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", h + i);
  }
  Part ans = Solve(0, n, 0);
  int sum = 0;
  for (int i = 0; i < S; ++i) {
    Add(sum, ans.val[i]);
  }
  printf("%d\n", sum);
  return 0;
}

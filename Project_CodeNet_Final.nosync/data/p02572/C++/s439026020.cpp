#include <bits/stdc++.h>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;

#define MAX_NUM (1000000007)
#define PI 3.14159265358979323846

using namespace std;

template <typename T>
static inline void ArrayInput(vector<T> &A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cin >> *itr;
}

template <typename T>
static inline void ArrayPut(const vector<T> &A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cout << *itr << " ";
  cout << endl;
}

template <typename T>
static inline T ArraySum(vector<T> &A) {
  T res = 0;
  for (auto itr = A.begin(); itr < A.end(); ++itr) res += *itr;
  return res;
}

bool Sec_compare(pair<uint64_t, uint64_t> a, pair<uint64_t, uint64_t> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first > b.first;
  }
}

u64 dec_dig(u64 num) {
  u64 res = 0;
  while (num > 0) {
    num /= 10;
    ++res;
  }
  return res;
}

i64 modinv(i64 a, i64 m) {
  i64 b = m, u = 1, v = 0;
  while (b) {
    i64 t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

u64 gcd(u64 a, u64 b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

i64 My_Comb(u64 n, u64 k, i64 m) {
  if (n < k) return 0;
  if (k == 0 || n == k) return 1;
  u64 res = 1;
  k = (n / 2 < k) ? n - k : k;
  for (u64 i = 1; i <= k; ++i)
    res = (((res * (n + 1 - i)) % m) * modinv(i, m)) % m;
  return res;
}

i64 My_Pow(u64 a, u64 n, i64 m) {
  u64 tmp = n, calc = 1;
  while (tmp > 0) {
    if (tmp % 2) {
      tmp--;
      calc *= a;
      calc %= m;
    } else {
      a *= a;
      a %= m;
      tmp /= 2;
    }
  }
  return calc;
}

class UnionFind {
 public:
  vector<u64> Par;
  vector<u64> sz;

  UnionFind(u64 n);
  u64 root(u64 x);
  bool same(u64 x, u64 y);
  void unite(u64 x, u64 y);
  u64 size(u64 x);
};

UnionFind::UnionFind(u64 n) {
  Par.resize(n);
  sz.assign(n, 1);
  for (u64 i = 0; i < n; ++i) Par[i] = i;
}

u64 UnionFind::root(u64 x) {
  if (Par[x] == x) {
    return x;
  } else {
    return Par[x] = root(Par[x]);
  }
}

bool UnionFind::same(u64 x, u64 y) { return root(x) == root(y); }

u64 UnionFind::size(u64 x) { return sz[root(x)]; }

void UnionFind::unite(u64 x, u64 y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  Par[y] = x;
}

template <typename T>
i64 BinSearch(vector<T> &V, i64 comp) {
  i64 l = 0, r = V.size() - 1;
  if (V[l] > V[r]) swap(l, r);
  if (V[l] >= comp) return l;
  if (V[r] <= comp) return r;
  while (abs(r - l) > 1) {
    i64 index = (l + r) / 2;
    if (V[index] == comp)
      return index;
    else if (V[index] > comp)
      r = index;
    else
      l = index;
  }
  if (abs(V[l] - comp) < abs(V[r] - comp))
    return l;
  else
    return r;
}
bool isPrime(u32 n) {
  if (n == 2) return true;
  if (n % 2) return false;
  for (u32 i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

i64 calc(vector<i64> &A, u32 K) {
  i64 res = 1;
  for (u32 i = 0; i < K; ++i) {
    res *= A[i];
    res %= MAX_NUM;
    if (res < 0) res += MAX_NUM;
  }
  return res;
}

int main() {
  cout << setprecision(18);

  u32 N;
  cin >> N;

  vector<i64> A(N);
  ArrayInput(A);
  vector<i64> Sum(N);
  Sum[0] = A[0];
  for (u32 i = 1; i < N; ++i) {
    Sum[i] = Sum[i - 1] + A[i];
  }

  u64 res = 0;

  for (u32 i = 0; i < N; ++i) {
    i64 tmp = Sum[N - 1] - Sum[i];
    tmp %= MAX_NUM;
    res += A[i] * tmp;
    res %= MAX_NUM;
  }

  cout << res << endl;

  return 0;
}

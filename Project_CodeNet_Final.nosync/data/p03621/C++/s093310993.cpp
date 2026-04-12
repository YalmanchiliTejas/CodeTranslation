#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;

const int N = 1 << 15;
const int M = 998244353;
inline int add(int x, int y) {return x+y>=M ? x+y-M : x+y;}
template<class ...Args> inline int add(int x, int y, Args... args) {return add(add(x, y), args...);}
inline int sub(int x, int y) {return x-y<0 ? x-y+M : x-y;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
template<class ...Args> inline int mul(int x, int y, Args... args) {return mul(mul(x, y), args...);}
inline void inc(int &x, int y=1) {x += y; if(x >= M) x -= M;}
inline void dec(int &x, int y=1) {x -= y; if(x < 0) x += M;}
inline int power(int x, int y){
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x){return power(x, M - 2);}
inline int reduce(int x) {return x + (M & (x >> 31));}
const int G = 3;
int W[N], invW[N], rev[N], ninv[N + 4], last = 0;
void init(){
  W[0] = invW[0] = 1;
  W[1] = power(G, (M - 1) / N); invW[1] = inv(W[1]);
  for(int i=2; i<N/2; i++){
    W[i] = mul(W[i - 1], W[1]);
    invW[i] = mul(invW[i - 1], invW[1]);
  }
  ninv[1] = 1;
  for(int i=2; i<=N; i++) ninv[i] = mul(ninv[M % i], M - M / i);
}
void make_rev(int n){
  if(n == last) return;
  int l = __builtin_ctz(n) - 1;
  last = n;
  for(int i=1; i<n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
}
int polylen(int x) {
  int l = 1;
  while (l <= x) l <<= 1;
  return l;
}
void dft(int a[], int n, int w[] = W){
  make_rev(n);
  for(int i=1; i<n; i++)
    if(i < rev[i]) swap(a[i], a[rev[i]]);
  for(int l=2, k=1; k<n; l<<=1, k<<=1){
    const int step = N / l;
    for(int i=0; i<n; i+=l)
      for(int j=0, e=0; j<k; j++, e+=step){
        int x = a[i + j], y = mul(a[i + j + k], w[e]);
        a[i + j] = add(x, y);
        a[i + j + k] = sub(x, y);
      }
  }
}
void idft(int a[], int n, int pres){
  dft(a, n, invW);
  int iN = ninv[n];
  for(int i=0; i<pres; i++) a[i] = mul(a[i], iN);
  fill(a + pres, a + n, 0);
}
void idft(int a[], int n){
  dft(a, n, invW);
  int iN = ninv[n];
  for(int i=0; i<n; i++) a[i] = mul(a[i], iN);
}
void Dot(int a[], const int b[], const int n){
  for(int i=0; i<n; i++) a[i] = mul(a[i], b[i]);
}
void Inv(const int a[], int b[], const int n){ // AB = 1, B = 2B_0 - AB_0^2
  static int ta[N];
  fill_n(ta, n << 1, 0); fill_n(b, n << 1, 0);
  b[0] = inv(a[0]);
  for(int l=2; l<=n; l<<=1){
    copy_n(a, l, ta);
    dft(ta, l << 1); dft(b, l << 1);
    for(int i=0; i<(l<<1); i++) b[i] = 1LL * b[i] * reduce(2 - 1LL * ta[i] * b[i] % M) % M;
    idft(b, l << 1, l);
  }
}
void D(int a[], int b[], int n){
  for(int i=1; i<n; i++)
    b[i - 1] = mul(i, a[i]);
  b[n - 1] = 0;
}
void Int(int a[], int b[], int n){
  for(int i=n-2; i>=0; i--)
    b[i + 1] = mul(b[i], ninv[i + 1]);
  b[0] = 0;
}
void Ln(int a[], int b[], int n){ // B = lnA = A' / A
  static int ia[N];
  D(a, b, n); fill(b + n, b + (n << 1), 0);
  Inv(a, ia, n);
  dft(ia, n << 1); dft(b, n << 1); Dot(b, ia, n << 1); idft(b, n << 1, n);
  Int(b, b, n);
}
void Exp(int a[], int b[], int n){ // B = B0(1 - ln B0 + A) 
  fill(b, b + (n << 1), 0);
  b[0] = 1;
  static int f[N];
  fill_n(f, n << 1, 0);
  for(int l=2; l<=n; l<<=1){
    Ln(b, f, l);
    for(int i=0; i<l; i++) f[i] = sub(a[i], f[i]);
    inc(f[0]);
    dft(b, l << 1); dft(f, l << 1); Dot(b,f , l << 1); idft(b, l << 1, l);
  }
}

char A[N], B[N];

int fac[N], ifac[N];
void pre_factorial(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}

int F[N], T[N];

int main() {
  init();
  scanf("%s%s", A, B);
  int len = strlen(A);
  int e = 0, k = 0;
  for (int i = 0; i < len; ++i) {
    k += int(A[i] == '1' || B[i] == '1');
    e += int(A[i] != B[i]);
  }
  e /= 2;
  k -= e;
  pre_factorial(k + 1);
  for (int i = 0; i <= k - e; ++i)
    F[i] = ifac[i + 1];
  int l = polylen(k - e + 1);
  Ln(F, T, l);
  for (int i = 0; i < l; ++i)
    T[i] = mul(T[i], e);
  Exp(T, F, l);
  int s = 0;
  for (int i = 0; i <= k - e; ++i)
    inc(s, F[i]);
  printf("%d\n", mul(s, fac[k], fac[k - e], fac[e]));
  return 0;
}
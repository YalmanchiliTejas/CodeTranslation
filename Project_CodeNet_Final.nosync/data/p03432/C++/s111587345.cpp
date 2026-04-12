#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long i64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 8e3+5, M = 2e2+5, P = 998244353;
int lim, rev[N<<2]; i64 g[N<<2];
i64 qpow(i64 a, int b) { i64 ret = 1; for( ; b; b >>= 1, a = a*a%P) if(b&1) ret = ret*a%P; return ret;  } 
void prepare(int ti)
{
    for(lim = 1; lim <= ti; lim <<= 1);
    i64 gn = qpow(3, (P-1)/lim); g[0] = 1;
    for(int i = 1, j = lim>>1; i < lim; ++i) 
    {
        g[i] = g[i-1]*gn%P, rev[i] = j;
        for(int k = lim>>1; (j ^= k) < k; k >>= 1);
    }
}
struct Poly
{
    vector<int> A;
    int& operator [] (const int i) { return A[i]; }
    void set(int ti) { A.resize(ti+1); }
    int ti() { return A.size()-1; }
    void ntt(int t)
    {
        if(!t)
        {
            A.resize(lim); for(int i = 1; i < lim; ++i) if(i > rev[i]) swap(A[i], A[rev[i]]);
            for(int mid = 1; mid < lim; mid <<= 1)
                for(int j = 0, len = mid<<1; j < lim; j += len)
                    for(int k = 0, p = 0, q = lim/len; k < mid; ++k, p += q)
                    {
                        i64 t = g[p]*A[j+k+mid]%P;
                        A[j+k+mid] = (A[j+k]-t+P)%P, A[j+k] = (A[j+k]+t)%P;
                    }
        }
        else 
        {
            reverse(++A.begin(), A.end()), ntt(0); i64 v = qpow(lim, P-2);
            for(int i = 0; i < lim; ++i) A[i] = A[i]*v%P;
        }
    }
    friend Poly operator * (Poly A, Poly B)
    {
        int n = A.ti(), m = B.ti(); prepare(n+m), A.ntt(0), B.ntt(0);
        for(int i = 0; i < lim; ++i)  A[i] = 1ll*A[i]*B[i]%P;
        A.ntt(1), A.set(n+m); return A; 
    }
}A, B;
int n, m, f[N][M], ans; i64 ifac[N], fac[N];
i64 C(int n, int m) { return fac[n]*ifac[m]%P*ifac[n-m]%P; }
int main()
{
    n = read(), m = read(), f[0][0] = 1, A.set(n);
    fac[0] = 1; for(int i = 1; i <= n+2; ++i) fac[i] = fac[i-1]*i%P;
    ifac[n+2] = qpow(fac[n+2], P-2); for(int i = n+2; i; --i) ifac[i-1] = ifac[i]*i%P;
    for(int i = 1; i <= n; ++i) A[i] = ifac[i+2];
    for(int j = 1; j <= m; ++j)
    {
        B.set(n); for(int i = 0; i <= n; ++i) B[i] = f[i][j-1]*ifac[i]%P; B = A*B; 
        for(int i = 0; i <= n; ++i) f[i][j] = (f[i][j-1]*(1+(i+1ll)*i/2)%P+B[i]*fac[i+2]%P)%P;
    }
    for(int i = 0; i <= n; ++i) ans = (ans+C(n, i)*f[i][m]%P)%P;
    printf("%d\n", ans);
    return 0;
}
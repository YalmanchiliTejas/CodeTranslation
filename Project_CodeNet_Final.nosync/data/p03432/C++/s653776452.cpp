#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define MAXN 8005
#define eps 1e-8
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) { res = 0;char c = getchar();T f = 1; while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); } while(c >= '0' && c <= '9') { res = res * 10 + c - '0'; c = getchar(); } res *= f; }
template<class T>
void out(T x) { if(x < 0) {x = -x;putchar('-');} if(x >= 10) { out(x / 10); } putchar('0' + x % 10); }
const int MOD = 998244353,MAXL = 1 << 14;
int N,M,fac[MAXN * 2],invfac[MAXN * 2],inv[MAXN * 2];
int f[MAXL + 5],g[MAXL + 5],dp[2][MAXN],W[MAXL + 5];
int mul(int a,int b) { return 1LL * a * b % MOD; }
int inc(int a,int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int C(int n,int m) { if(n < m) return 0; return mul(fac[n],mul(invfac[m],invfac[n - m])); }
int fpow(int x,int c) { int res = 1,t = x; while(c) { if(c & 1) res = mul(res,t); t = mul(t,t); c >>= 1; } return res; }
void update(int &x,int y) { x = inc(x,y); }
void FFT(int *p,int L,int on) {
    for(int i = 1 , j = L >> 1 ; i < L - 1 ; ++i) { if(i < j) swap(p[i],p[j]); int k = L >> 1; while(j >= k) { j -= k; k >>= 1; } j += k; }
    for(int h = 2 ; h <= L ; h <<= 1) {
    int wn = W[(MAXL + on * (MAXL / h)) % MAXL];
    for(int k = 0 ; k < L ; k += h) {
        int w = 1;
        for(int j = k ; j < k + h / 2 ; ++j) {
        int u = p[j],t = mul(w,p[j + h / 2]);
        p[j] = inc(u,t);
        p[j + h / 2] = inc(u,MOD - t);
        w = mul(w,wn);
        }
    }
    }
    if(on == -1) {
    int InvL = fpow(L,MOD - 2);
    for(int i = 0 ; i < L ; ++i) p[i] = mul(p[i],InvL);
    }
}
void Solve() {
    read(N);read(M);
    fac[0] = 1; for(int i = 1 ; i <= N + 10 ; ++i) fac[i] = mul(fac[i - 1],i);
    invfac[N + 10] = fpow(fac[N + 10],MOD - 2); for(int i = N + 9 ; i >= 0 ; --i) invfac[i] = mul(invfac[i + 1],i + 1);
    W[0] = 1;W[1] = fpow(3,(MOD - 1) / MAXL); for(int i = 2 ; i < MAXL ; ++i) W[i] = mul(W[i - 1],W[1]);
    int cur = 0; for(int i = 0 ; i <= N ; ++i) dp[cur][i] = 1; for(int i = 1 ; i <= N ; ++i) g[i] = invfac[i + 2];
    int L = 1; while(L <= 2 * N) L <<= 1;
    FFT(g,L,1);
    for(int i = 2 ; i <= M ; ++i) {
    memset(dp[cur ^ 1],0,sizeof(dp[cur ^ 1]));
    for(int j = 0 ; j <= N ; ++j) { update(dp[cur ^ 1][j],mul(dp[cur][j],inc(C(j + 1,2),1))); }
    memset(f,0,sizeof(f)); for(int j = 0 ; j <= N ; ++j) f[j] = mul(dp[cur][j],invfac[j]);
    FFT(f,L,1); for(int j = 0 ; j < L ; ++j) f[j] = mul(f[j],g[j]); FFT(f,L,-1);
    for(int j = 0 ; j <= N ; ++j) { update(dp[cur ^ 1][j],mul(f[j],fac[j + 2])); }
    cur ^= 1;
    }
    int ans = 0;
    for(int i = 0 ; i <= N ; ++i) { update(ans,mul(C(N,i),dp[cur][i])); }
    out(ans);enter;
}
int main() {
    Solve();
    return 0;
}
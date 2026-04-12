#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 1005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 +c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N,A,B,C,D;
int dp[MAXN][MAXN],c[MAXN][MAXN],fac[MAXN],invfac[MAXN],g[MAXN];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
int fpow(int x,int c) {
    int res = 1,t = x;
    while(c) {
        if(c & 1) res = mul(res,t);
        t = mul(t,t);
        c >>= 1;
    }
    return res;
}
void Solve() {
    read(N);read(A);read(B);read(C);read(D);
    c[0][0] = 1;
    for(int i = 1 ; i <= N ; ++i) {
        c[i][0] = 1;
        for(int j = 1 ; j <= i ; ++j) {
            c[i][j] = inc(c[i - 1][j],c[i - 1][j - 1]);
        }
    }
    fac[0] = 1;
    for(int i = 1 ; i <= N ; ++i) fac[i] = mul(fac[i - 1],i);
    invfac[N] = fpow(fac[N],MOD - 2);
    for(int i = N - 1 ; i >= 0 ; --i) {
        invfac[i] = mul(invfac[i + 1],i + 1);
    }
    dp[0][0] = 1;
    for(int i = 1 ; i <= B - A + 1; ++i) {
        int t = i + A - 1;

        for(int j = 0 ; j <= N ; ++j) {
            dp[i][j] = dp[i - 1][j];
            for(int k = C ; k <= D ; ++k) {
                if(k * t > j) break;
                int tmp = mul(dp[i - 1][j - k * t],c[N - j + k * t][k * t]);
                tmp = mul(fac[k * t],tmp);
                tmp = mul(tmp,fpow(invfac[t],k));
                tmp = mul(tmp,invfac[k]);
                update(dp[i][j],tmp);
            }
        }
    }
    out(dp[B - A + 1][N]);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

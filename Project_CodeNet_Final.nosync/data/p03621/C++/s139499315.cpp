#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 10005
#define eps 1e-12
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
        res = res * 10 + c - '0';
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
const int MOD = 998244353,MAXL = (1 << 16);
char a[MAXN],b[MAXN];
int N,k,d,fac[MAXN],invfac[MAXN],W[MAXL];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
int C(int n,int m) {
    if(n < m) return 0;
    return mul(fac[n],mul(invfac[m],invfac[n - m]));
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
struct poly {
    vector<int> v;
    void limit(int n = -1) {
        if(n != -1) v.resize(n);
        while(v.size() > 1 && (v.back()) == 0) v.pop_back();
    }
    friend void NTT(poly &f,int L,int on) {
        f.v.resize(L);
        for(int i = 1, j = L >> 1 ; i < L - 1 ; ++i) {
            if(i < j) swap(f.v[i],f.v[j]);
            int k = L >> 1;
            while(j >= k) {
                j -= k;
                k >>= 1;
            }
            j += k;
        }
        for(int h = 2 ; h <= L ; h <<= 1) {
            int wn = W[(MAXL + on * MAXL / h) % MAXL];
            for(int k = 0 ; k < L ; k += h) {
                int w = 1;
                for(int j = k ; j < k + h / 2 ; ++j) {
                    int u = f.v[j],v = mul(w,f.v[j + h / 2]);
                    f.v[j] = inc(u,v);
                    f.v[j + h / 2] = inc(u,MOD - v);
                    w = mul(w,wn);
                }
            }
        }
        if(on == -1) {
            int invL = fpow(L,MOD - 2);
            for(int i = 0 ; i < L ; ++i) {
                f.v[i] = mul(f.v[i],invL);
            }
        }
    }
    friend poly operator * (poly a,poly b) {
        poly c;c.v.clear();
        int s = a.v.size() + b.v.size();
        int L = 1;
        while(L <= s) L <<= 1;
        NTT(a,L,1);NTT(b,L,1);
        for(int i = 0 ; i < L ; ++i) {
            c.v.pb(mul(a.v[i],b.v[i]));
        }
        NTT(c,L,-1);
        return c;
    }
    friend poly fpow(const poly &a,int c,int n) {
        poly res,t = a;
        res.v.clear();res.v.pb(1);
        while(c) {
            if(c & 1) {
                res = res * t;
                res.limit(n);
            }
            t = t * t;t.limit(n);
            c >>= 1;
        }
        return res;
    }
}f;
void Solve() {
    scanf("%s%s",a + 1,b + 1);
    N = strlen(a + 1);
    for(int i = 1 ; i <= N ; ++i) {
        if(a[i] == '1') {
            ++k;
            if(b[i] == '0') ++d;
        }
    }
    fac[0] = 1;

    for(int i = 1 ; i <= N ; ++i) {
        fac[i] = mul(fac[i - 1],i);
    }
    invfac[N] = fpow(fac[N],MOD - 2);
    for(int i = N - 1 ; i >= 0 ; --i) {
        invfac[i] = mul(invfac[i + 1],i + 1);
    }
    W[0] = 1;W[1] = fpow(3,(MOD - 1) / MAXL);
    for(int i = 2 ; i < MAXL ; ++i) W[i] = mul(W[i - 1],W[1]);
    f.v.clear();
    f.v.resize(N);
    for(int i = 1 ; i <= k ; ++i) {
        f.v[i] = invfac[i];
    }
    f = fpow(f,d,N);
    int ans = 0;
    for(int i = d ; i <= k ; ++i) {
        if(i > f.v.size() - 1) break;
        int t = mul(f.v[i],mul(fac[i],fac[d]));
        t = mul(t,C(k,i));
        t = mul(t,mul(fac[k - d],fac[k - i]));
        ans = inc(ans,t);
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Solve();
}

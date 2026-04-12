#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define enter putchar('\n')
#define space putchar(' ')
#define fi first
#define se second
#define mp make_pair
#define ba 47
#define mo 999999137
#define mod 974711
//#define ivorysi
#define pii pair<int,int>
using namespace std;
typedef long long int64;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
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
    if(x < 0) {putchar('-');x = -x;}
    if(x >= 10) out(x / 10);
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N;
int h[105];
bool vis[105];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
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
void update(int &x,int y) {
    x = inc(x,y);
}
pii Solve(int l,int r,int v) {
    int minv = 1e9;
    for(int i = l ; i <= r ; ++i) minv = min(minv,h[i]);
    int p,cnt = 0;
    pii res = mp(1,1);
    for(int i = l ; i <= r ; ++i) {
	if(h[i] > minv) ++cnt;  
    }
    for(int i = l ; i <= r ; ++i) {
	if(h[i] > minv) {
	    p = i;
	    while(p < r && h[p + 1] > minv) ++p;
	    pii f = Solve(i,p,minv);
	    res.fi = mul(res.fi,f.fi);
	    res.se = mul(res.se,inc(f.se,f.fi));
	    i = p;
	}
    }
    int t = mul(res.fi,2);
    res.se = mul(res.se,fpow(2,r - l + 1 - cnt));
    res.fi = mul(res.fi,fpow(2,minv - v));
    res.se = inc(res.se,inc(res.fi,MOD - t));
    return res; 
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {read(h[i]);}
    pii ans = Solve(1,N,0);
    out(ans.se);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

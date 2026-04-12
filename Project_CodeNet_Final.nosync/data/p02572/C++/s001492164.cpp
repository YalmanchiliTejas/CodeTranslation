#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif


#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

template <typename T>
inline bool read(T& ret) {
    T x = 0, f = 1; char ch = getchar();
    while(ch!=EOF && (ch > '9' || ch < '0')) { if(ch == '-') f = -1; ch = getchar();  }
    if(EOF==ch)return false;
    do x = x * 10 + ch - 48, ch = getchar(); while(ch >= '0' && ch <= '9');
    ret = x * f;
    return true;
}


inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
template <typename T>
bool rn(T& v) {
    static char ch;
    while (ch != EOF && !isdigit(ch)) ch = nc();
    if (ch == EOF) return false;
    for (v = 0; isdigit(ch); ch = nc())
        v = v * 10 + ch - '0';
    return true;
}

template <typename T>
void o(T p) {
    static int stk[70], tp;
    if (p == 0) { putchar('0'); return; }
    if (p < 0) { p = -p; putchar('-'); }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
}


LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }



void Solve(){
}

int N;
const int MOD=1e9+7;
LL A[200010];

int main(){
#ifdef L_JUDGE
    freopen("in1.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    while(EOF!=scanf("%d", &N)){
        LL tmpsum=0;
        LL ans=0;
        for(int i=0;i<N;i++){
            scanf("%lld", A+i);
            ans = ans+tmpsum*A[i];
            ans%=MOD;
            tmpsum+=A[i];
            tmpsum%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

	return 0;
}

#ifndef LOCAL
#pragma GCC optimize ("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define mor > muu & operator << (
#define R22(r) sim > typename \
  enable_if<1 r sizeof dud<c>(0), muu&>::type operator<<(c g) {
sim > struct rge { c b, e; };
sim > rge<c> range(c h, c n) { return {h, n}; }
sim > auto dud(c* r) -> decltype(cerr << *r);
sim > char dud(...);
struct muu {
#ifdef LOCAL
stringstream a;
~muu() { cerr << a.str() << endl; }
R22(<) a << boolalpha << g; ris; }
R22(==) ris << range(begin(g), end(g)); }
sim, class b mor pair < b, c > r) { ris << "(" << r.first << ", " << r.second << ")"; }
sim mor rge<c> u) {
  a << "[";
  for (c i = u.b; i != u.e; ++i)
    *this << ", " + 2 * (i == u.b) << *i;
  ris << "]";
}
#else
sim mor const c&) { ris; }
#endif
muu & operator()() { ris; }
};
#define imie(r...) "[" #r ": " << (r) << "] "
#define imask(r...) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) ": " << a[i][j] << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")

const int N = 2e5 + 7;
vector <pair <int, int>> prz[N];
long long dp[N];
int n, m;

const int M = (1 << 18);
long long D[2 * M];
long long W[2 * M];

long long inf = 1e18;

void insert(int a, int b, long long w, int v = 1, int p = 0, int k = M - 1) {
    if (a <= p && k <= b) {
        W[v] += w;
        return;
    }
    W[2 * v] += W[v];
    W[2 * v + 1] += W[v];
    W[v] = 0;
    int s = (p + k) / 2;
    if (a <= s) insert(a, b, w, 2 * v, p, s);
    if (s + 1 <= b) insert(a, b, w, 2 * v + 1, s + 1, k);
    D[v] = max(W[2 * v] + D[2 * v], W[2 * v + 1] + D[2 * v + 1]);
}

int main() {
    scanf("%d %d", &n, &m);
    long long wynik = 0;
    for (int i = 1; i <= m; ++i) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        prz[r].push_back({l, -c});
        wynik += c;
    }
    
    for (int i = 0; i < 2 * M; ++i) {
        D[i] = -inf;
    }
    
    insert(0, 0, inf);
    
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto u : prz[i]) {
            if (u.first >= 2) insert(0, u.first - 2, u.second);
            sum += u.second;
        }
        
        dp[i] = max(sum, D[1]);
        insert(i, i, inf + dp[i]);
    }
    
    printf("%lld\n", wynik + dp[n]);
    return 0;
}

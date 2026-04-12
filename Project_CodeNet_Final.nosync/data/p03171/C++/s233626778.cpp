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

const int N = 3e3 + 7;
int a[N];
long long dp[N][N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    
    for (int i = 1; i <= n; ++i) {
        if (n % 2 == 1) dp[i][i] = a[i];
        else dp[i][i] = -a[i];
    }
    
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i + l - 1 <= n; ++i) {
            int j = i + l - 1;
            if (l % 2 == n % 2) dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
            else dp[i][j] = min(-a[i] + dp[i + 1][j], -a[j] + dp[i][j - 1]);
        }
    }
    
    printf("%lld\n", dp[1][n]);
    return 0;
}

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

const int N = 1e4 + 7;
const int M = 107;
const int mod = 1e9 + 7;

long long ile[N][M];
char numC[N];
int num[N];
int d;

int main() {
    scanf("%s", numC + 1);
    int n = strlen(numC + 1);
    for (int i = 1; i <= n; ++i) num[i] = numC[i] - '0';
    scanf("%d", &d);
    
    ile[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < d; ++j) {
            ile[i][j] %= mod;
            for (int z = 0; z < 10; ++z) {
                ile[i + 1][(j + z) % d] += ile[i][j];
            }
        }
    }
    
    long long wynik = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int z = 0; z < num[i]; ++z) wynik += ile[n - i][(2 * d - (sum + z % d)) % d];
        for (int z = 0; z < num[i]; ++z) debug << imie(i) << imie(z) << imie((2 * d - (sum + z % d)) % d) << ile[n - i][(2 * d - (sum + z % d)) % d];
        sum = (sum + num[i]) % d;
    }
    
    wynik += mod - 1;
    
    if (sum == 0) wynik++;
    
    printf("%lld\n", wynik % mod);
    return 0;
}

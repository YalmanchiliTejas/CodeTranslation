#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <queue>
#include <thread>
#include<bits/extc++.h>

using namespace __gnu_pbds;
#pragma GCC optimize("Ofast")

#define ll long long

#define gc (c = getchar())
#define gi(x) scanf("%d", &x)
#define gid(x, y) scanf("%d%d", &x, &y)
#define gll(x) scanf("%lld", &x)
#define glld(x, y) scanf("%lld%lld", &x, &y)
#define gllt(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define git(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pi(x) printf("%d\n", x)
#define pr(x) return !(printf("%lld\n", (long long)(x)))
#define pcs(ch, cs, x) printf("Case %c%d: %d\n", ch, cs, x)
#define pllcs(ch, cs, x) printf("Case %c%d: %lld\n", ch, cs, x)
#define pcsyn(ch, cs, st) printf("Case %c%d: %s\n", ch, cs, (st) ? "Yes" : "No")
#define pyn(st) printf("%s\n", (st) ? "yes" : "no")
#define pryn(st) return !(printf("%s\n", (st) ? "YES" : "NO"))
#define pll(x) printf("%lld\n", x)
#define plld(x, y) printf("%lld %lld\n", x, y)

#define mp(x, y) std::make_pair(x, y)
#define fcs(x) while (x--)
#define dbg(x) std::cerr << #x << " " << x << std::endl
#define fi freopen("in.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define siz(x) (int)x.size()
#define pb(x) push_back(x)

inline long long max(long long x, long long y) { return x > y ? x : y; }

inline long long min(long long x, long long y) { return x > y ? y : x; }

long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }


const int maxn = 2e5 + 5;
long long seq[maxn];
const long long mod = 1e9 + 7;
int main(){
    int n;
    gi(n);
    for (int i = 1; i <= n; ++ i) gll(seq[i]);
    long long sum = 0, ret = 0;
    for (int i = n; i >= 1; -- i){
        ret = (ret + sum * seq[i]) % mod;
        sum = (sum + seq[i]) % mod;
    }
    pll(ret);
} 
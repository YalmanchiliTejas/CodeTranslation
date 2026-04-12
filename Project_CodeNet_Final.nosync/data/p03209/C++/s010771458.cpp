#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#define LL long long
#define MAXN 100010
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

inline LL read() { LL x = 0, f = 1; char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) f = ch == '-' ? -1 : 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0'; return x * f;
}

const int MOD = 1e9 + 7;int n;
LL k;
LL sum[MAXN];

LL mi(LL a, int b) {
    LL ans = 1;
    while(b) {
        if(b % 2) ans *= (LL)a;
        a *= a;
        b /= 2;
    }
    return ans;
}

LL sol(int n, LL k) {
    //debug(k);

    if(n == 0) return k > 0;
    LL x = mi(2, n + 2) - 3ll;
    //debug((x));
    if(k > (x >> 1) + 1ll) {
        return sol(n - 1, k - (x >> 1) - 1ll) + sum[n - 1] + 1ll;
    }
    if(k > (x >> 1)) return sol(n - 1, k - 1) + 1ll;
    return sol(n - 1, k - 1);
}

LL tot[MAXN];

int main() {
    //debug(mi(2, 52));
    n = (int)read();
    k = read();
    sum[0] = 1; tot[0] = 1;
    for(int i = 1; i <= n; ++i) {
        sum[i] = (sum[i - 1] << 1) + 1ll;
        tot[i] = (tot[i - 1] << 1) + 3ll;
//        debug(tot[i]);
//        debug(sum[i]);
    }
    //debug(k - tot[n] / 2 - 1);
    printf("%lld\n", sol(n, k));
    return 0;
}

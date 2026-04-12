#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <time.h>
#pragma warning(disable:4996) 

typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define LINF3 1000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;


ll mpow(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll minv(ll x){
    return mpow( x, MOD-2 );
}

void solve()
{
    int n;
    scanf("%d", &n);

    vector<ll> a(n);
    ll s = 0, s2 = 0;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s = (s + a[i]) % MOD;
        s2 = (s2 + a[i] * a[i]) % MOD;
    }
    ll ans = (s*s - s2) % MOD*minv(2) % MOD;
    printf("%lld\n", ans);

    return;
}

int main()
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for (t = 0; t < T; t++) {
        //printf("Case #%d: ", t + 1);
        solve();
    }
#endif
    return 0;
}

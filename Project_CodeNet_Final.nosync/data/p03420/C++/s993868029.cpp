#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(ll i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;
#define MAX_N 100010

ll N, K;

signed main()
{
    cin >> N >> K;

    if(K == 0) {
        printf("%lld\n", N * N);
        return 0;
    }

    ll ans = 0;
    for(ll b = 1; b <= N; ++b) {
        ll x = (N / b) + 1;
        ll y = x * K;
        ll z = (N % b) + 1;
        if((N % b) >= K) { z = K; }
        ll w = y - (K - z) - 1;
        ll res = N - w;
        //DBG("b: %lld res: %lld\n", b, res);
        if(res > 0) { ans += res; }
    }
    printf("%lld\n", ans);
    return 0;
}

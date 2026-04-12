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
#define MAX_N 200010

ll N;
vector<ll> X, Y;

signed main()
{
    cin >> N;
    REP(i, N) {
        ll tmp;
        cin >> tmp;
        X.push_back(tmp);
        Y.push_back(tmp);
    }
    SORT(X);
    REP(i, N) {
        ll ans;
        if(Y[i] < X[N/2]) { ans = X[N/2]; }
        else { ans = X[N/2 - 1]; }
        printf("%lld\n", ans);
    }
    return 0;
}

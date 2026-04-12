#include <bits/stdc++.h>

using namespace std;

#define rep(x,a,b)         for(int x = a; x < b; x++)
#define per(x,a,b)         for(int x = a; x >= b; x--)
#define all(container)     (container).begin(), container.end()
#define rall(container)    (container).rbegin(), container.rend()
#define sz(container)      (int) (container).size()
#define pb                 push_back
#define eb                 emplace_back
#define fi                 first
#define sc                 second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool smin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool smax(T &a, T b) { return a < b ? (a = b, true) : false; }

#ifdef LOCAL_DEFINE
    #include "DEBUG.hpp"
#else
    #define debug(...) 0
#endif
const ll mod = 1e9 + 7;
const int maxn = 200010;
ll arr[maxn], suff[maxn];
int main(void)
{
    int n;
    scanf("%d", &n);
    rep(i,0,n) scanf("%lld", &arr[i]);
    suff[n-1] = arr[n-1];
    per(i,n-2,0) suff[i] = (arr[i] + suff[i + 1]) % mod;
    ll ans = 0;
    rep(i,0,n-1) ans = (ans + arr[i] * suff[i + 1] % mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
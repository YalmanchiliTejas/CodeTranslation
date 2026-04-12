#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a > b){a = b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a < b){a = b;return true;}return false;}
ll invmod(ll a, ll p)
{ // a^-1 mod p
    ll b = p, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= p;
    if (u < 0)
        u += p;
    return u;
}
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    REP(i,n){
        cin >> a[i];
        sum+=a[i];
        sum%=MOD;
    }
    ll ans=0;
    REP(i,n){
        ans = (ans + (a[i] * (sum + MOD - a[i]) % MOD) % MOD) % MOD;
    }
    ans=ans*invmod(2,MOD)%MOD;
    ans%=MOD;
    cout << ans << endl;
}

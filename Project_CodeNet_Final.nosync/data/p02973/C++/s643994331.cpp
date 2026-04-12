#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

ll modpow(ll a, ll p)
{
    if (p == 0)
        return 1;
    if (!(p % 2))
    {
        ll halfP = p / 2;
        ll half = modpow(a, p);
        return half * half % mod;
    }
    else
    {
        return a * modpow(a, p - 1) % mod;
    }
}

ll comb(int a, int b)
{
    if (b > a - b)
        return comb(a, a - b);
    ll ansMul = 1;
    ll ansDiv = 1;
    for (int i = 0; i < b; i++)
    {
        ansMul *= a - i;
        ansDiv *= i + 1;
        ansMul %= mod;
        ansDiv %= mod;
    }
    ll ans = ansMul * modpow(ansDiv, mod - 2) % mod;
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<int> d;
    rep(i, n) {
        int p = lower_bound(all(d), a[i]) - d.begin();
        if (p == 0) {
            d.push_front(a[i]);
        }
        else {
            d[p-1] = a[i];
        }
    }
    int ans = d.size();
    cout << ans << endl;
    return 0;
}
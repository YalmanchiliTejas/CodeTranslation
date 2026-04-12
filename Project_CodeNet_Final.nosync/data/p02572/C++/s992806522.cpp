#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
// #define int long long

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mod = (int) 1e9+7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi a(n);
    REP(i, n) {
        cin >> a[i];
        a[i] = a[i]%mod;
    }

    ll acc = 0;
    REP(i, n) {
        acc += a[i];
        acc %= mod;
    }

    ll ans = 0;
    REP(i, n) {
        //cout << acc << endl;
        acc -= a[i];
        // cerr << acc << endl;
        if (acc < 0) acc += mod;
        ans += (a[i]* acc)%mod;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}

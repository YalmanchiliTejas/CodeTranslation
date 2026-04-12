#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REPR(i, n) for (ll i = (n); i >= 0; i--)
#define FOR(i, m, n) for (ll i = (m); i < (n); i++)
#define FORR(i, m, n) for (ll i = (m); i >= (n); i--)
#define INF 1e9
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
#define SORT(x) sort((x).begin(), (x).end())
#define dump(x) cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl

int main(int argc, char const *argv[])
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll res = INF;
    REP(i, max(x, y) + 1)
    {
        ll tmp = i * 2 * c;
        if (x > i)
            tmp += (x - i) * a;
        if (y > i)
            tmp += (y - i) * b;
        // dump(res);
        // dump(tmp);
        res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
}

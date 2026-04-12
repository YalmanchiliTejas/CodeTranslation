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
    vector<ll> p;
    p.push_back(a * x + b * y);
    // dump(a * x + b * y);
    p.push_back(c * max(x, y) * 2);
    // dump(c * max(x, y) * 2);
    ll tmp = 0;
    if (x < y)
    {
        tmp += 2 * x * c;
        tmp += (y - x) * b;
    }
    else
    {
        tmp += 2 * y * c;
        tmp += (x - y) * a;
    }
    // dump(tmp);
    p.push_back(tmp);
    cout << *min_element(ALL(p)) << endl;
    return 0;
}

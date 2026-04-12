#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

ll n, x;

int main() {
    cin >> n >> x;

    V<Pll> p(51);
    p[0] = {1, 0};
    REP2(i, 1, 51) {
        p[i] = {1+2*p[i-1].first, 2+2*p[i-1].second};
    }

    ll res = 0;
    while (n >= 0 && x > 0) {
        if (x <= (p[n].first + p[n].second) / 2) {
            n--;
            x--;
        } else if (x == (p[n].first + p[n].second) / 2 + 1) {
            if (n == 0) {
                res += 1;
            } else {
                res += p[n-1].first + 1;
            }
            break;
        } else {
            res += p[n-1].first + 1;
            x -= (p[n].first + p[n].second) / 2 + 1;
            n--;
        }
    }
    cout << res << '\n';

    return 0;
}

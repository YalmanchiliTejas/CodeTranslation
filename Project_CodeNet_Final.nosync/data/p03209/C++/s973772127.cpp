#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
#define ALL(x) x.begin(), x.end()
#define INF (1001000000)
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i:c)
#define EXIST(cs,v) (find(ALL(cs),(v))!=cs.end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define UNIQ(c) (c).erase(unique((c).begin(),(c).end()), (c).end());
#define P(p) cout<<(p)<<endl;

ll pLayer(ll num) {
    if (num == 0) return 1;
    return 2 * pLayer(num-1) + 1;
}

ll wholeLayer(ll num) {
    if (num == 0) return 1;
    return 2 * wholeLayer(num-1) + 3;
}

ll f(ll n, ll x, vector<ll> a, vector<ll> p) {
    if (n == 0) {
        if (x <= 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (x <= 1 + a[n-1]) {
        return f(n-1, x-1, a, p);
    }
    else {
        return p[n-1] + 1 + f(n-1, x-2-a[n-1], a, p);
    }

}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    vector<ll> a, p;
    REP(i, n) {
        a.push_back(wholeLayer(i));
        p.push_back(pLayer(i));
    }


    P(f(n, x, a, p));

    return 0;
}

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = INF;
    // i: A, j: Bの枚数
    // for(ll i=0; i<=x; ++i)
    //     for(ll j=0; j<=y; ++j) {
    //         ll k = max(2 * (x - i), 2 * (y - j));
    //         ll tmp = a * i + b * j + c * k;
    //         if(tmp < ans) ans = tmp;
    //     }

    for(ll k = 0; k <= max(2 * x, 2 * y); ++k) {
        ll i = max(x - k / 2, 0ll);
        ll j = max(y - k / 2, 0ll);
        ll tmp = a * i + b * j + c * k;
        if(tmp < ans) ans = tmp;
    }

    cout << ans << endl;
    return 0;
}
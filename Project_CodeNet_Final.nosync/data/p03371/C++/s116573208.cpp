#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)


int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll res = 1e18;
    rep(k, max(x, y) + 1) {
        int i = max(0ll, x - k);
        int j = max(0ll, y - k);
        res = min(res, (a * i) + (b * j) + (c * 2 * k));
    }
    cout << res << endl;
    return 0;
}


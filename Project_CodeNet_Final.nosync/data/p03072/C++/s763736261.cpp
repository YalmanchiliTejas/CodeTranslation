#include <iostream>
#include <iomanip>
#include <tuple>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>
using namespace std;
void init();
#ifdef DEBUG_BUILD
#define DBG(expr) cout << #expr << " = " << expr << endl;
#endif
#define ECHO(expr) cout << expr << endl;
#define REP(var, num) for(ll var = 0; var < num; var++)
#define REP_FROM(var, from, num) for(ll var = from; var < num; var++)
#define MAX_OF(type) numeric_limits<type>::max()
#define MIN_OF(type) numeric_limits<type>::min()
#define SORT(vec) sort(vec.begin(), vec.end())
#define REVERSE(vec) reverse(vec.begin(), vec.end())
#define T_FIRST(tuple) (std::get<0>(tuple))
#define T_SECOND(tuple) (std::get<1>(tuple))
#define T_THIRD(tuple) (std::get<2>(tuple))
typedef signed long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll max_h = 0;
    REP(i, n) {
        ll h;
        cin >> h;
        if (h >= max_h) {
            ans++;
            max_h = h;
        }
    }

    ECHO(ans)
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

#ifdef INPUT_FILE
    if (!freopen(INPUT_FILE, "r", stdin)) {
        perror("freopen");
        exit(1);
    }
#endif

    solve();
    return 0;
}
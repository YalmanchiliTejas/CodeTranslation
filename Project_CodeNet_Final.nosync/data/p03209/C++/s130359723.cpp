#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

ll burger(int level) {
    if (level == 0) return 1;
    return burger(level - 1) * 2 + 3;
}

ll patti(int level) {
    if (level == 0) return 1;
    return patti(level - 1) * 2 + 1;
}

ll eat(int level, ll x) {
    if (level == 0 && x == 1) return 1;
    if (x <= 1) return 0;
    if (burger(level) - x < 2) return patti(level);

    x--;
    ll ret = 0;
    if (x >= burger(level - 1)) {
        x -= burger(level - 1);
        ret += patti(level - 1);
        if (x == 0) return ret;
        else {
            x--;
            ret++;
        }
    }
    return ret + eat(level - 1, x);
}

int main() {
    ll N, X;
    cin >> N >> X;
    cout << eat(N, X) << endl;
    return 0;
}
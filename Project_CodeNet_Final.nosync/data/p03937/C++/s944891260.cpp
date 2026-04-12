#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    ll H, W;
    cin >> H >> W;

    vector<string> S(H);

    ll count = 0;

    rep(i, H) {
        cin >> S[i];
        rep(j, W) {
            if (S[i][j] == '#') {
                count++;
            }
        }
    }

    if (count == W + H - 1) {
        cout << "Possible";
    }
    else {
        cout << "Impossible";
    }

    return 0;
}

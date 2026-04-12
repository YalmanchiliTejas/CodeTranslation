#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    while (true) {
        ll cnt = 0;
        rep(i, n) {
            cnt += a[i] / n;
        }

        rep(i, n) {
            a[i] = a[i] - (a[i] / n) * n + (cnt - a[i] / n);
        }

        ans += cnt;

        if (cnt == 0) break;
    }

    cout << ans << endl;

    return 0;

}

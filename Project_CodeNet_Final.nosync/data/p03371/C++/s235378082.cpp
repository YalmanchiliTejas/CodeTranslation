#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define int long long

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

signed main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int n = a * x + b * y;
    int m = 2 * c * max(x, y);

    int p   = x < y ? b : a;
    int l   = 2 * c * min(x, y) + p * abs(x - y);
    int ans = min(n, min(m, l));
    cout << ans << endl;
}

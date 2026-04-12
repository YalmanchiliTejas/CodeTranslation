#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    int ans = INF;
    for(int i = 0; i <= 2 * max(x, y); i++) {
        int cntA = max(x - i / 2, (int)0);
        int cntB = max(y - i / 2, (int)0);
        int tmp = i * c + cntA * a + cntB * b;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}

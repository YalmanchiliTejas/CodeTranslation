#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b>> c >> x >> y;
    int ans = a*x + b*y;
    for (int i = 0; i <= max(x, y); i++) {
        ans = min(ans, a*max(x-i, 0) + b*max(y-i, 0) + c*i*2);
    }
    cout << ans << endl;
}

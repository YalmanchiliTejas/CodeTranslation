#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

#define LL long long
LL a, b, c, x, y;

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL

    while(cin >> a >> b >> c >> x >> y) {
        if(x > y) {
            swap(x, y);
            swap(a, b);
        }
        LL ans = a * x + b * y;
        ans = min(ans, x * 2 * c + (y - x) * b);
        ans = min(ans, y * 2 * c);
        cout << ans << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
using namespace std;
 
long long p[55], sz[55];
 
long long dfs(long long n, long long x) {
    if (n == 0) return x <= 0 ? 0 : 1;
    if (x <= sz[n - 1] + 1) return dfs(n - 1, x - 1);
    return p[n - 1] + 1 + dfs(n - 1, x - sz[n - 1] - 2);
}
 
int main() {
    p[0] = 1, sz[0] = 1;
    for (int i = 1; i <= 50; i++) {
        p[i] = 2 * p[i - 1] + 1;
        sz[i] = 2 * sz[i - 1] + 3;
    }
    long long n, x;
    cin >> n >> x;
    cout << dfs(n, x) << endl;
    return 0;
}
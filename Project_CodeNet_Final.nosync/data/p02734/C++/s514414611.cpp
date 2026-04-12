#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

const int maxn = 3002;
const int mo = 998244353;

int n, m, ans = 0;
long long f[maxn];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        f[0] = i+1;
        if (v <= m) {
            ans = (ans + f[m-v] * (n-i) % mo) % mo;
            for (int j = m; j >= v; --j)
                f[j] = (f[j] + f[j-v]) % mo;
        }
    }
    cout << ans << endl;

	return 0;
}
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

int n;
long long f[maxn][maxn], sum[maxn];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        sum[i] = sum[i-1] + d;
    }

    for (int j = 1; j <= n; ++j) {
        f[j][j] = sum[j] - sum[j-1];

        for (int i = j-1; i > 0; --i)
            f[i][j] = sum[j] - sum[i-1] - min(f[i+1][j], f[i][j-1]);
    }
	
    cout << 2 * f[1][n] - sum[n] << endl;

	return 0;
}
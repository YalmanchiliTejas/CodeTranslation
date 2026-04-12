// better!

// 数位 DP
// 状态一般可以表示为 f[i][stats][bound]s

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

const int maxn = 10002;
const int mo = 1e9 + 7;

int f[maxn][102][2];

void add(int &a, int b) {
    a = (a + b) % mo;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, d;
    string s;
    cin >> s >> d;
	
    n = s.length();
    if (n == 1) {
        int tmp = (s[0] - '0' >= d) ? 1 : 0;
        cout << tmp << endl;
        return 0;
    }

    vector<int> lim(n);
    for (int i = 0; i < n; ++i)
        lim[i] = s[i] - '0';

    for (int i = 0; i < lim[0]; ++i)
        ++f[0][i % d][0];
    f[0][lim[0]%d][1] = 1;

    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < d; ++j)
            for (int k = 0; k < 2; ++k)
                if (f[i][j][k] != 0) {
                    int curlim = k == 1 ? lim[i+1] : 9;
                    for (int t = 0; t <= curlim; ++t)
                        add(f[i+1][(j+t)%d][k && (t == lim[i+1])], f[i][j][k]);
                }

    int res = ((f[n-1][0][0] + f[n-1][0][1]) % mo - 1 + mo) % mo;
    cout << res << endl;
	return 0;
}
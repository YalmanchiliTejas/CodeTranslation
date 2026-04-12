#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <iterator>
#include <string>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
int int_max = 2147483647;
int max_n = 1e5;
using mat2d_t = std::vector<std::vector<int64_t>>;

int main(int argc, char **argv) {
    string s;
    int k;
    cin >> s >> k;

    int len = s.size();

    mat2d_t dp0 = mat2d_t(len, std::vector<i64>(4, 0)); // smaller
    mat2d_t dp1 = mat2d_t(len, std::vector<i64>(4, 0)); // smaller?

    dp0[0][0] = 1;

    for (int i = 0; i<len; ++i) {
        s[i] -= '0';
        if (i == 0) {
            dp0[0][1] = s[i]-1;
            dp1[0][1] = 1;
            continue;
        }
        dp0[i][0] = 1;
        for (int j=1; j<=k; ++j) {
            dp0[i][j] += dp0[i-1][j-1] * 9;
            dp0[i][j] += dp0[i-1][j];

            if (s[i]) {
                dp0[i][j] += dp1[i-1][j];
                dp0[i][j] += dp1[i-1][j-1] * (s[i]-1);
                dp1[i][j] += dp1[i-1][j-1];
            } else {
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }

    cout << dp0[len-1][k] + dp1[len-1][k] << endl;

    return 0;
}

#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <utility>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<ll> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    vector<vector<ll> > dp(n + 1, vector<ll>(n + 1));

    for(int len = 1; len < n + 1; ++len) {
        for(int left = 0; left + len < n + 1; ++left) {
            int right = left + len;

            if((right - left) % 2 == n % 2) {
                dp[left][right] = max(v[left] + dp[left + 1][right],
                                      dp[left][right - 1] + v[right - 1]);
            } else {
                dp[left][right] = min(-v[left] + dp[left + 1][right],
                                      dp[left][right - 1] - v[right - 1]);
            }
        }
    }

    /*
    for(int i = 0; i < n + 1; ++i) {
        copy(dp[i].begin(), dp[i].end(), ostream_iterator<ll>(cout, " "));
        cout << endl;
    }
    */

    cout << dp[0][n] << endl;

    return 0;
}

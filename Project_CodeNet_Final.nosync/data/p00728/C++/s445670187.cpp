#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <limits>
#include <cmath>
#include <cassert>

using namespace std;
using ll = long long;

const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n, n)
    {
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 1; i < n - 1; i++)
        {
            ans += v[i];
        }
        ans /= n - 2;
        cout << ans << endl;
    }
    return 0;
}



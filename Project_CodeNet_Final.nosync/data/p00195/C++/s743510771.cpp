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
    int s, t;
    while(cin >> s >> t, s or t)
    {
        vector<int> shop(5, 0);
        shop[0] = s + t;
        for(int i = 1; i <= 4; i++)
        {
            cin >> s >> t;
            shop[i] = s + t;
        }
        int maxv = 0;
        char ans;
        for(int i = 0; i < 5; i++)
        {
            if(maxv < shop[i])
            {
                maxv = shop[i];
                ans = 'A' + i;
            }
        }
        cout << ans << " " << maxv << endl;
    }
    return 0;
}



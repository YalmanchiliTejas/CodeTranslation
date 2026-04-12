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
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 101;
    while(ans--)
    {
        int tmp = 0;
        for(int i = 0; i < n; i++)
        {
            if(v[i] + tmp < ans) break;
            tmp = (v[i] + tmp) - ans;
            if(i == n - 1)
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}



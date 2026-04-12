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
    int N, T, E; cin >> N >> T >> E;
    vector<int> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < N; i++)
    {
        int t = x[i];
        while(t <= T + E)
        {
            if(T - E <= t and t <= T + E)
            {
                cout << i + 1 << endl;
                return 0;
            }
            t += x[i];
        }
    }
    cout << -1 << endl;
    return 0;
}



#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
#include <cctype>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)

const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    string k;
    int d;
    cin >> k;
    cin >> d;
    vector<vector<int>>dp( k.size() + 15, vector<int>(d + 10,0));
    dp[0][0] = 1;
    for(int i = 0; i < k.size(); i++){
        for(int j = 0; j <  d; j++){ // текущий остаток
            for(int ij = 0; ij <= 9; ij++){
                dp[i + 1][(j + ij)%d] += dp[i][j];
                dp[i + 1][(j + ij)%d] %= mod;
            }
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < k.size(); i++) {
        for (int j = 0; j < k[i] - '0'; j++) {
            ans += dp[k.size() - i - 1][(2 * d - sum - j % d) % d];
            ans %= mod;
        }
        sum += k[i] - '0';
        sum %= d;
    }
    if (sum == 0) {
        ans += 1;
    }
    ans += mod - 1;
    ans %= mod;
    cout << ans << endl;
    return 0;
}

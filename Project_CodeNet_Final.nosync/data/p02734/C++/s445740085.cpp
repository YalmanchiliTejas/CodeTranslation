#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
#include <numeric>

//usings
using namespace std;

//type def
typedef long long int64;
typedef pair<int, int> ii;

//consts
const int mod = 998244353;

//methods
template<typename T>
bool chmax(T& source, const T& compare_to) {
    if(source < compare_to) {
        source = compare_to;
        return true;
    }
    return false;
}

int modpow(int64 base, int n) {
    int64 ret = 1;
    while(n) {
        if(n & 1) ret = ret * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return ret;
}

class Solution {
private:
public:
    int solve(int n, int k, vector<int>& arr) {
        vector<vector<vector<int64>>> dp(n + 1, vector<vector<int64>>(k + 1, vector<int64>(3)));
        //int64 dp[n + 1][k + 1][3] = {};
        dp[0][0][0] = 1;
        for(int i = 0; i < n; ++i) {
            for(int s = 0; s <= k; ++s) {
                (dp[i + 1][s][0] += dp[i][s][0]) %= mod;
                (dp[i + 1][s][1] += dp[i][s][0] + dp[i][s][1]) %= mod;
                (dp[i + 1][s][2] += dp[i][s][0] + dp[i][s][1] + dp[i][s][2]) %= mod;
                if(s + arr[i] <= k) {
                    (dp[i + 1][s + arr[i]][1] += dp[i][s][0] + dp[i][s][1]) %= mod;
                    (dp[i + 1][s + arr[i]][2] += dp[i][s][0] + dp[i][s][1]) %= mod;
                }
            }
        }
        return dp[n][k][2];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    Solution sol;
    auto ret = sol.solve(n, k, arr);
    cout << ret << endl;
}
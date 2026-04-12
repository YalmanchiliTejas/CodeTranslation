#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>

//usings
using namespace std;

//type def
typedef long long int64;
typedef pair<int, int> ii;

//consts
const int mod = 1e9 + 7;

//methods
template<typename T>
bool chmax(T& source, const T& compare_to) {
    if(source < compare_to) {
        source = compare_to;
        return true;
    }
    return false;
}

class Solution {
private:
    
public:
    int64 solve(vector<int64>& arr, int n) {
        vector<vector<int64>> dp(n + 1, vector<int64>(4, INT64_MIN / 2));
        dp[0][0] = 0;
        int k = n % 2 + 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= k; ++j) {
                chmax(dp[i + 1][j + 1], dp[i][j]);
                int64 cur = dp[i][j];
                if((i + j) % 2 == 0) cur += arr[i];
                chmax(dp[i + 1][j], cur);
            }
        }
        return dp[n][k];
    }
};

int main() {
    
    int n;
    cin >> n;
    vector<int64> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Solution sol;
    auto ret = sol.solve(arr, n);
    cout << ret << endl;
}
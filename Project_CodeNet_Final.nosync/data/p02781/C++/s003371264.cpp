#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

ll dp[105][2][5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int K;
    cin >> s >> K;
    int n = s.length();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i){
        int num = s[i] - '0';
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k <= K; ++k){
                if(!dp[i][j][k])    continue;
                for(int x = 0; x <= (j ? 9 : num); ++x){
                    dp[i + 1][j | (x < num)][k + (x != 0)] += dp[i][j][k]; 
                }
            }
        }
    }
    int ans = dp[n][0][K] + dp[n][1][K];
    cout << ans << endl;
}
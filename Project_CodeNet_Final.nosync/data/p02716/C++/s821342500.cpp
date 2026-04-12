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
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)  cin >> a[i];

    constexpr ll inf = 1e+17;
    int extra = n % 2 + 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(extra + 2, -inf));
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= extra; ++j){
            chmax(dp[i + 1][j + 1], dp[i][j]);
            ll now = dp[i][j];
            if((i + j) % 2 == 0)    now += a[i];
            chmax(dp[i + 1][j], now);
        }
    }

    cout << dp[n][extra] << endl;
}
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
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<int, pair<int, int>> PP;
typedef pair<P, int> PPi;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
// constexpr int mod = 1e+9 + 7;
constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

ll dp[3005][3005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)  cin >> a[i];

    for(int i = 0; i < n; ++i){
        chadd(dp[i][0], 1);
        for(int j = 0; j <= s; ++j){
            if(dp[i][j] == 0)   continue;
            chadd(dp[i + 1][j], dp[i][j]);
            if(j + a[i] <= s)   chadd(dp[i + 1][j + a[i]], dp[i][j]);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) chadd(ans, dp[i][s]);
    cout << ans << endl;
}
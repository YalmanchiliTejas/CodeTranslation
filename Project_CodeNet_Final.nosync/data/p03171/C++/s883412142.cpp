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

constexpr ll inf = 1e+15;
int n;
vector<int> a;
ll dp[2][3005][3005];

ll memo_rec(int Turn = 0, int Left = 0, int Right = n){
    if(dp[Turn][Left][Right] != -inf)   return dp[Turn][Left][Right];
    if(Right - Left == 1)   return dp[Turn][Left][Right] = a[Left] * (Turn ? -1 : 1);

    ll res = 0;
    if(Turn == 0){
        ll foo = memo_rec(Turn ^ 1, Left + 1, Right) + a[Left];
        ll bar = memo_rec(Turn ^ 1, Left, Right - 1) + a[Right - 1];
        res = max(foo, bar);
    }
    else{   // Turn == 1
        ll foo = memo_rec(Turn ^ 1, Left + 1, Right) - a[Left];
        ll bar = memo_rec(Turn ^ 1, Left, Right - 1) - a[Right - 1];
        res = min(foo, bar);
    }

    return dp[Turn][Left][Right] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i)  cin >> a[i];

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = j + 1; k <= n; ++k){
                dp[i][j][k] = -inf;
            }
        }
    }
    cout << memo_rec() << endl;
}
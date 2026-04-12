#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
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
using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const int mod = 1e+9 + 7;

// 入力
vector<ll> a;

// dp[left][right] := 区間 [left,right] での解
vector<vector<ll>> dp(3005, vector<ll>(3005, -1));

// メモ化再帰
// turn : 手番  (true, false) = (先手, 後手)
ll memo_rec(int left, int right, bool turn = true){
    if(dp[left][right] != -1)   return dp[left][right];

    int sign = (turn) ? 1 : -1;
    if(left == right){
        return dp[left][right] = sign * a[left];
    }
    
    ll x1 = memo_rec(left + 1, right, turn ^ 1) + sign * a[left];
    ll x2 = memo_rec(left, right - 1, turn ^ 1) + sign * a[right];

    if(turn)    return dp[left][right] = max(x1, x2);
    else    return dp[left][right] = min(x1, x2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    cout << memo_rec(0, n - 1) << endl;
}
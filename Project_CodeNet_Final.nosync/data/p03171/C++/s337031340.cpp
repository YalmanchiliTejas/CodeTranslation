// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

int N, dp[3010][3010], A[3010];

const int TARO = 0;
const int JIRO = 1;

int solve(int l, int r, int turn=TARO) {
    int &val = dp[l][r];
    if(val != INF) return val;
    if(l == r) return val = 0;
    
    val = (turn == TARO ? -INF : INF);
    if(turn == TARO) {
        chmax(val, A[l  ] + solve(l+1, r, 1 - turn));
        chmax(val, A[r-1] + solve(l, r-1, 1 - turn));
    }
    if(turn == JIRO) {
        chmin(val, solve(l+1, r, 1 - turn) - A[l  ]);
        chmin(val, solve(l, r-1, 1 - turn) - A[r-1]);
    }
    return val;
}

signed main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    fill(dp[0], dp[N+1], INF);
    cout << solve(0, N) << endl;
    return 0;
}

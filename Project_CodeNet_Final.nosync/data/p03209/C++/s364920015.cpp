// 基本テンプレート
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

int N, X;
int cntP[60], cntB[60], cntW[60];

int solve(int X, int level) {
    int sum = 0;
    if(level == 0) return 1;
    
    if(X == 1) {
        return 0;
    }
    X--;
    if(X <= cntW[level-1]) {
        return sum + solve(X, level-1);
    }
    X -= cntW[level-1]; sum += cntP[level-1];
    if(X == 1) {
        return sum + 1;
    }
    X--; sum++;
    if(X <= cntW[level-1]) {
        return sum + solve(X, level-1);
    }
    X -= cntW[level-1]; sum += cntP[level-1];
    if(X == 1) {
        return sum;
    }
    assert(false);
    return 0;
}

signed main() {
    cin >> N >> X;
    cntP[0] = 1, cntB[0] = 0, cntW[0] = 1;

    for(int i=1; i<=N; i++) {
        cntP[i] = 2 * cntP[i-1] + 1;
        cntB[i] = 2 * cntB[i-1] + 2;
        cntW[i] = cntP[i] + cntB[i];
    }

    cout << solve(X, N) << endl;
    return 0;
}

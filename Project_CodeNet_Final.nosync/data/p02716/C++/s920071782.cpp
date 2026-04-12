#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }

ll score(int N ,int i, int j, vll& Seven, vll& Sodd) {
    if(i - 1 < 0) return Sodd[N] - Sodd[j] + Seven[j - 1] - Seven[i];
    return Sodd[i - 1] + Sodd[N] - Sodd[j] + Seven[j - 1] - Seven[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];
    int M = 1 + N % 2;
    v2ll dp(N + 1, vll(M + 1, -LINF));
    dp[0][0] = 0;
    REP(i, 0, N) {
        REP(j, 0, M + 1) {
            if(j < M)
                dp[i + 1][j + 1] =max(dp[i + 1][j + 1], dp[i][j]);
            if ((i + 1 + j) % 2 == 1)
                dp[i + 1][j] =max(dp[i + 1][j], dp[i][j] + A[i]);
            else
                dp[i + 1][j] =max(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}
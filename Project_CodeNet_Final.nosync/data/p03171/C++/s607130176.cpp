#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 10000000000000000
#define int long long
int dp[3010][3010];
int a[3010];
int N; 
int calc(int L = 0, int R = N - 1, int turn = 1) {
    if(L > R) return 0;
    if(dp[L][R] != -INF2) return dp[L][R];
    int ret;
    if(turn) {
        int c1 = calc(L + 1, R, !turn) + a[L];
        int c2 = calc(L, R - 1, !turn) + a[R];
        ret = max(c1, c2);
    } else {
        int c1 = calc(L + 1, R, !turn) - a[L];
        int c2 = calc(L, R - 1, !turn) - a[R];
        ret = min(c1, c2);
    }
    return dp[L][R] = ret;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    
    rep(i, N) cin >> a[i];
    rep(i, 3010) rep(j, 3010) dp[i][j] = -INF2;
    cout << calc() << endl;

    return 0;
}

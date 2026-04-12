#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
int dp[110][4][2];
string S;
int calc(int x, int k, int smaller) {
    //cout << x << " " << k << " " << smaller << endl;
    if(k < 0) return 0;
    if(x < 0 && k == 0) return 1;
    else if(x < 0 && k != 0) return 0;
    if(dp[x][k][smaller] != -1) return dp[x][k][smaller];
    if(smaller) {
        return dp[x][k][smaller] = calc(x - 1, k, smaller) + calc(x - 1, k - 1, smaller) * 9;
    } else {
        //cout << S[x] << endl;
        if(S[x] == '0')
            return dp[x][k][smaller] = calc(x - 1, k, 0);
        else
            return dp[x][k][smaller] = calc(x - 1, k - 1, 0) + calc(x - 1, k - 1, 1) * (S[x] - '0' - 1) + calc(x - 1, k, 1);
    }
    return -1;
}


signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    reverse(S.begin(), S.end());
    int K; cin >> K;
    rep(i, 110) rep(k, 4) rep(j, 2) dp[i][k][j] = -1;
    cout << calc((int)S.length() - 1, K, 0) << endl;
    //cout << calc(0, 1, 1) << endl;

    return 0;
}

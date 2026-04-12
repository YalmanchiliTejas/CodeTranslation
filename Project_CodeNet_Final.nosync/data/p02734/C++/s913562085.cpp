#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#define int long long
#define REP(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define Pii pair< int, int > 
#define Pid pair< int, double > 
#define Pdd pair< double, double > 
#define MOD 998244353
#define EPS 0.00000001

using namespace std;

signed main() {
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    REP(i,n) cin >> a.at(i);
    vector<vector<int> > dp(3001, vector<int>(n+1));
    dp[0][0] = 1;
    for(int i = 1; i < n+1; i++) {
        dp[0][i] = ((i + 1) * (i + 2) / 2) % MOD;
    }
    for(int i = 1; i < 3001; i++) {
        //j = 1
        if (i == a[0]) dp[i][1] = 1;
        for(int j = 2; j < n+1; j++) {
            dp[i][j] = (dp[i][j-1] * 2 - dp[i][j-2] + MOD) % MOD;
            if (i >= a[j-1]) dp[i][j] = (dp[i][j] + dp[i - a[j-1]][j-1] - dp[i - a[j-1]][j-2] + MOD) % MOD;
        }
    }
    /*
    REP(i,10) {
        REP(j,n+1) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    */
    cout << dp[s][n] % MOD << "\n";
    return 0;
}
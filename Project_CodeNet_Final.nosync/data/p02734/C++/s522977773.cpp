#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <array>
#include <deque>
#include <bitset>
typedef long long ll;
using namespace std;
#define trace(x) cerr << #x << " is " << x << endl;
ll dp[3001][3001][3];
const ll MOD = 998244353;

ll solve(vector<int>&a, int n, int k) {
    dp[0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            (dp[i+1][j][0] += dp[i][j][0]) %= MOD;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= MOD;
            if(j + a[i] <= k){
                (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
                (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            }
        }
    }
    return dp[n][k][2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << solve(a, n, k) <<endl;
    return 0;
}
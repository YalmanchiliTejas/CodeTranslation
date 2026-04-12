#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FOR(i, i0, n) for(int i = (i0); i < (n); i ++)
#define COUT(val) cout << (val) << "\n";
using namespace std;
using ll = long long int;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];
    
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i = 0; i < n; i ++) dp[i][i] = a[i];
    for(int s = 1; s < n; s ++){
        for(int l = 0; l+s < n; l ++){
            int r = l+s;
            dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
        }
    }
    
    COUT(dp[0][n-1]);
}
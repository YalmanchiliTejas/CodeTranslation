#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[10001][101][2];

int solve(string &K,int &D, int pos, int d, bool tight) {
    if(dp[pos][d][tight] != -1) return dp[pos][d][tight];
    
    int ub = (tight) ? (K[pos] - '0') : 9;
    int len = K.length()-1;
    if(pos == len) {
        int ans = 0;
        for(int x=0; x<=ub; x++) if(x%D == d) ans++;
        return ans;
    }

    int ans = 0;
    for(int x=0; x<=ub; x++) ans = (ans + solve(K, D, pos+1, (D + d - x%D)%D, tight && (x == ub)))%mod;
    return dp[pos][d][tight] = ans;
}

int32_t main() {
    string K;
    int D;
    cin>>K>>D;
    memset(dp, -1, sizeof dp);
    cout<< (mod + solve(K, D, 0, 0, 1) -1)%mod;
    return 0;
}

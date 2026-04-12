#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int a[10002], n, d; ll dp[10002][102][2]; string s;
ll solve(int pos, int sum, bool lmt){
    if(pos == n) return sum == 0;
    if(dp[pos][sum][lmt] != -1) return dp[pos][sum][lmt];
    int hi = lmt? a[pos]: 9; ll ret = 0;
    for(int i=0; i<=hi; i++){
        ret += solve(pos+1, (sum+i)%d, lmt && (i==a[pos])); 
    }
    return dp[pos][sum][lmt] = ret % mod;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> s >> d; n = s.size();
    for(int i=0; i<n; i++) a[i] = s[i] - '0';
    cout << ( solve(0, 0, 1) - 1 + mod) % mod << endl;
}
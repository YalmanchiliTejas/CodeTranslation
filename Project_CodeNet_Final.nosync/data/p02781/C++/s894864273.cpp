#include<bits/stdc++.h>
using namespace std;
long long dp[103][4][2], mod = 1e9 + 7;
int k, n;
string s;
long long solve(int pos, int occ, bool flag){
    if(occ > k){
        return 0;
    }
    if(dp[pos][occ][flag] != -1){
        return dp[pos][occ][flag];
    }
    if(pos == n){
        if(occ == k){
            dp[pos][occ][flag] = 1;
        }
        else{
            dp[pos][occ][flag] = 0;
        }
        return dp[pos][occ][flag];
    }
    dp[pos][occ][flag] = 0;
    int lim;
    if(flag == 0){
        lim = s[pos] - '0';
    }
    else{
        lim = 9;
    }
    for(int i = 0; i <= lim; i++){
        int nocc = occ + (i != 0);
        int nflag = (flag == 1 || i < lim);
        dp[pos][occ][flag] = (dp[pos][occ][flag] + solve(pos + 1, nocc, nflag)) % mod;
    }
    return dp[pos][occ][flag];
}
int main(){
    cin >> s >> k;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0);
    return 0;
}
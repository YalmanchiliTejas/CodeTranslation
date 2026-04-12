#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int dp[20005][100][2] , D , M = 1e9+7;
string num; 

int solve(int pos , int rem , int flag , int n) {
    if(pos == n) {
        if(rem == 0) return 1;
        else return 0;
    }
    else if(dp[pos][rem][flag] != -1) return dp[pos][rem][flag];
    int lmt , res = 0;
    if(!flag) lmt = 9;
    else lmt = num[pos]-'0'; 
    for(int i = 0; i <= lmt; i++) {
        if(i < num[pos]-'0') res = (res + solve(pos+1 , (rem+i)%D , 0 , n))%M;
        else res = (res + solve(pos+1 , (rem + i)%D , flag, n))%M;
    }
    dp[pos][rem][flag] = res;
    return dp[pos][rem][flag];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> num >> D;
    int n = num.length();
    memset(dp , -1 , sizeof(dp));
    cout << (solve(0, 0, 1, n) - 1 + M)%M << "\n";

    return 0;
}


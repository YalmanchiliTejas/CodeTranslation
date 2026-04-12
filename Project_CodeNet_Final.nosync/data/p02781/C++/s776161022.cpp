#include <bits/stdc++.h>
#include <iostream>
#define BELOW 1
#define NOTBELOW 0
using namespace std;
typedef long long ll;
string N;
int num[105];
int K;
int totZeros;
ll dp[105][105][2]; // digits, zeros, below or not

ll solve(int dig, int zeros, int below){
    //cout << dig << " " << zeros << " " << below << endl;
    if (dp[dig][zeros][below] != -1) return dp[dig][zeros][below];
    //if (dig == 2 && zeros == 5 && below == 1) cout << "ok" << endl;
    if (totZeros-zeros > dig+1) return dp[dig][zeros][below] = 0;
    //if (dig == 2 && zeros == 5 && below == 1) cout << "ok" << endl;
    if (dig == 0){
        if (below){
            if (zeros == totZeros) return dp[dig][zeros][below] = 9;
            if (zeros == totZeros-1) return dp[dig][zeros][below] = 1;
            else return dp[dig][zeros][below] = 0;
        }
        else {
            if (zeros == totZeros) return dp[dig][zeros][below] = num[0];
            if (zeros == totZeros-1) return dp[dig][zeros][below] = 1;
            else return dp[dig][zeros][below] = 0;
        }
    }
    ll ans = 0;
    if (below){
        ans += 9*solve(dig-1,zeros,below);
        if (zeros < totZeros) {
            //if (dig == 3 && zeros == 4 && below == 1) cout << zeros << " a " << totZeros << endl;
            ans += solve(dig-1,zeros+1,below);
        }
    }
    else {
        if (num[dig] != 0) ans += solve(dig-1,zeros,NOTBELOW);
        else ans += solve(dig-1, zeros+1, NOTBELOW);
        ans += max(0,num[dig]-1)*solve(dig-1,zeros,BELOW);
        if (zeros < totZeros && num[dig] != 0) ans += solve(dig-1, zeros+1, BELOW);
    }
    //cout << ans << " " << dig << " " << zeros << " " << below << endl;
    return dp[dig][zeros][below] = ans;
}

int main() {
    cin >> N >> K;
    int s = N.length();
    totZeros = s-K;
    //cout << totZeros << endl;
    for (int i=0; i<s; i++){
        num[s-1-i] = N[i]-'0';
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(s-1, 0, NOTBELOW) << endl;
//    for (int i=0; i<=3; i++){
//        for (int j=0; j<=3; j++){
//            for (int k=0; k<2; k++){
//                cout << dp[i][j][k] << " ";
//            }
//        }
//    }
//    cout << endl;
//    cout << dp[0][0][0] << endl;
//    cout << dp[0][0][1] << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const lint N = 110;
string n;
lint k, dp[N][N][2][2];

lint solve(lint digit, lint cnt, lint zero, lint flag){
    if (cnt < 0)
        return 0;

    if (digit == n.size()){
        if (cnt == 0){
            return 1;
        }
        return 0;
    }

    if (dp[digit][cnt][zero][flag] != -1) return dp[digit][cnt][zero][flag];

    lint res = 0;

    lint limit;

    if (flag)
        limit = n[digit]-'0';
    else
        limit = 9;

    //cout << digit << " " << limit << endl;

    for (lint d=0;d<=limit;d++){
        //cout << digit << " " << d << endl;
        if (d)
            res += solve(digit+1, cnt-1, zero, d==n[digit]-'0'?flag:0);
        else
            res += solve(digit+1, cnt, 1, d==n[digit]-'0'?flag:0);

    }

    return dp[digit][cnt][zero][flag] = res;
}

int main(){
    cin >> n;
    scanf("%lld", &k);

    memset(dp, -1, sizeof dp);

    printf("%lld\n", solve(0, k, 0, 1));

    //cout << dp[0][0][0]+dp[0][0][1] << endl;

    return 0;
}

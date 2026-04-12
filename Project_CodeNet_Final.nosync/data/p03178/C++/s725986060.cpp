#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

string k;
int d;

vector<int> digits;
int dp[(int)1e4+10][110][2];

int solve(int idx, int sum, int tight){
    // cout << idx << " " << sum << " " << tight << '\n';
    if(idx == -1) 
        return sum % d == 0;

    if(dp[idx][sum][tight] != -1 and tight != 1)
        return dp[idx][sum][tight];

    int ret = 0;

    int j = (tight) ? digits[idx] : 9;

    for(int i=0;i<=j;++i){
        int newTight = (digits[idx] == i) ? tight : 0;
        ret = (ret + solve(idx - 1, (sum + i) % d, newTight)) % MOD;
    }

    if(!tight)
        dp[idx][sum][tight] = ret;

    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> k >> d;

    digits = vector<int>(k.size());
    for(int i=0;i<k.size();++i)
        digits[i] = k[i] - '0';
    reverse(digits.begin(), digits.end());


    cout << (solve(k.size()-1, 0, 1) - 1 + MOD)%MOD << '\n';

    return 0;
}
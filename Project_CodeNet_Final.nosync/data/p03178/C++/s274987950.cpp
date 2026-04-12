#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;

const int mod = 1e9+7;
string s;
int mult;
int memo[2][101][10010] = {0};

int solve(int pos, int sumMod, bool allEqualSoFar) {
    if(pos == (int)s.size()) {
        if(sumMod == 0) return 1;
        return 0;
    }
    if(memo[allEqualSoFar][sumMod][pos] != -1) return memo[allEqualSoFar][sumMod][pos];
    int res = 0;
    if(allEqualSoFar) {
        for(int digit = 0; digit <= s[pos]-'0'; ++digit) {
            bool equal = (digit == s[pos]-'0');
            res += solve(pos+1, (sumMod+digit)%mult, allEqualSoFar&equal);
            res %= mod;
        }
    } else {
        for(int digit = 0; digit <= 9; ++digit) {
            res += solve(pos+1, (sumMod+digit)%mult, allEqualSoFar);
            res %= mod;   
        }
    }
    return memo[allEqualSoFar][sumMod][pos] = res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> mult;
    for(int i = 0; i < mult; ++i) {
        for(int j = 0; j < (int)s.size(); ++j) {
            memo[0][i][j] = -1;
            memo[1][i][j] = -1;
        }
    }
    //cout << solve(0,0,1) << '\n';
    int res = 0;
    for(int digit = 0; digit <= s[0]-'0'; ++digit) {
        bool equal = (digit == s[0]-'0');
        res += solve(1, digit%mult, equal);
        res %= mod;
    }
    cout << (res-1+mod)%mod << '\n';
    return 0;
}

























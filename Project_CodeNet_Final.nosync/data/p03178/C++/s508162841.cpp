//EDPC S
#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

string K;
int D;
int dp[10001][2][101];

int rec(int digit, int smaller, int num){
    if(dp[digit][smaller][num] != -1){
        return dp[digit][smaller][num];
    }
    if (digit == K.size()){
        return num == 0;
    }
    int lim = (smaller ? 9 : K[digit] - '0');
    int res = 0;
    for(int next = 0; next <= lim; next++){
        res += rec(digit + 1, smaller || (next < lim), (num + next) % D);
        res %= MOD;
    }
    return dp[digit][smaller][num] = res;
}

signed main(){
    cin >> K;
    cin >> D;
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 0, 0) + MOD - 1) % MOD << endl;
}
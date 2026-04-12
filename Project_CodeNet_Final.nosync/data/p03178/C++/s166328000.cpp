#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string n;
int d;
long long dp[10010][110][2];
const long long MOD = (long long)1e9 + 7;

long long calc(int k, int s, bool f){
    if(dp[k][s][f] >= 0) return dp[k][s][f];
    if(k == n.size()){
        if(s == 0)
            return dp[k][s][f] = 1;
        else
            return dp[k][s][f] = 0;
    }
    long long res = 0;
    int m = (f? n[k] - '0' : 9);
    for(int i = 0; i <= m; i++){
        res += calc(k + 1, (s + i) % d, f & (i == m));
        res %= MOD;
    }
    return dp[k][s][f] = res;
}

int main(){
    cin >> n >> d;
    for(auto&& i : dp){
        for(auto&& j : i){
            for(auto&& k : j){
                k = -1;
            }
        }
    }
    long long ans = (calc(0, 0, true) - 1 + MOD) % MOD;
    cout << ans << endl;
    return 0;
}

#include <iostream>
using namespace std;
const int mod = (int)1e9 + 7;
const int max_size = 2*(int)1e5+1;

long long sum[max_size] = {};
long long dp[max_size] = {};
int n;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    for(int i = 1,a; i <= n  ;++i){
        cin >> a;
        sum[i] = sum[i-1]+a;
        sum[i] %= mod;
        dp[i] = dp[i-1] + sum[i-1]*a;
        dp[i] %= mod;
    }
    cout << dp[n];
    
    return 0;
}
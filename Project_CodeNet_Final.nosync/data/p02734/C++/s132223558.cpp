#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;


int main() {
    int n, s;
    cin >> n >> s;
    long long ans = 0;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    vector<long long> dp(s + 1, 0);
    for(int i = 0; i < n; i++) {
        dp[0] = (dp[0] + 1) % mod;
        vector<long long> tmp(begin(dp), end(dp));
        for(int j = s; j >= arr[i]; j--) {
            tmp[j] = (tmp[j] + dp[j - arr[i]]) % mod;
        }   
        dp = tmp;
        ans = (ans + tmp[s]) % mod;
    }
    
    cout << ans << '\n';
    return 0;
}
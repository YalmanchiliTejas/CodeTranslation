#include<bits/stdc++.h>
 
using namespace std;

void solve(int TestCase) {
    constexpr int MOD = 998244353;
    int n, s;
    cin >> n >> s;
    auto A = vector<int>(n);
    for(auto& x : A)
        cin >> x;
    
    auto dp = vector<vector<long long>>(n, vector<long long>(3001));
    auto sum = vector<long long>(3001);
    for(auto i = 0; i < n; ++i)
    {
        dp[i][A[i]] = i+1;
        for(auto j = A[i] + 1; i && j < s+1; ++j)
        {
            dp[i][j] = sum[j - A[i]];
        }

        for(auto j = 0; j < s+1; ++j)
        {
            sum[j] = (sum[j] + dp[i][j]) % MOD;
        }
    }

    long long ret = 0;
    for(auto i = 0; i < n; ++i)
    {
        ret = (ret + dp[i][s] * (n - i) % MOD) % MOD;
    }

    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
    //    cout << "Case #"<< i << ": ";
        solve(i);
    }
}
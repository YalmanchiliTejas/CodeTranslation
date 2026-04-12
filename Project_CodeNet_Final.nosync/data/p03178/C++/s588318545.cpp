#include<bits/stdc++.h>

int main(){
    using namespace std;

    vector<unsigned long> digits;
    {
        string K;
        cin >> K;
        transform(begin(K), end(K), back_inserter(digits), [](char c){return c - 48;});
    }

    unsigned long D, N{digits.size()};
    cin >> D;

    vector<vector<vector<unsigned long>>> dp(N + 1, vector<vector<unsigned long>>(2, vector<unsigned long>(D, numeric_limits<unsigned long>::max())));

    cout << [dfs_impl = [&digits, &D, &N, &dp](auto f, unsigned long d, unsigned long l, unsigned long x) -> unsigned long {
        if(dp[d][l][x] + 1UL)return dp[d][l][x];
        if(d == N)return dp[d][l][x] = x ? 0 : 1;
        if(l){
            unsigned long ret{0};
            for(unsigned long i{0}; i < 10; ++i)ret += f(f, d + 1, l, (x + i) % D);
            return dp[d][l][x] = ret % 1000000007;
        }else{
            unsigned long ret{0};
            for(unsigned long i{0}; i <= digits[d]; ++i)ret += f(f, d + 1, i < digits[d], (x + i) % D);
            return dp[d][l][x] = ret % 1000000007;
        }
    }]{return (dfs_impl(dfs_impl, 0, 0, 0) + 1000000006) % 1000000007;}() << endl;

    return 0;
}
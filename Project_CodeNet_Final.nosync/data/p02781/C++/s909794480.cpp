#include<bits/stdc++.h>

int main()
{
    std::string s;
    long long k,n;
    std::cin >> s >> k;
    n = s.size();
    std::vector<std::vector<std::vector<long long>>> dp(n + 10,std::vector<std::vector<long long>>(200,std::vector<long long>(2)));
    dp[0][0][0] = 1;

    for(long long i = 0; i < n; i++){

        for(long long j = 0; j < 110; j++){

            for(long long t = 0; t < 2; t++){

                long long lim = (t ? 9 : s[i] - '0');
                for(long long d = 0; d <= lim; d++){
                    dp[i + 1][j + (d != 0)][t || d < lim] += dp[i][j][t];
                }
            }
        }
    }
    std::cout << dp[n][k][0] + dp[n][k][1] << std::endl;

}
#include<bits/stdc++.h>

const long long mod = 1000000007;

int main()
{
    std::string s;
    long long D,n;
    std::cin >> s >> D;
    n = s.size();
    //dp[i][j][k] := i文字目まで見た時にmodDでkで、未満フラグがjの数

    std::vector<std::vector<std::vector<long long>>> dp(n + 10,std::vector<std::vector<long long>>(2,std::vector<long long>(D)));
    dp[0][0][0] = 1;
    
    for(long long i = 0; i < n; i++){
        
        for(long long j = 0; j < 2; j++){
            
            for(long long k = 0; k < D; k++){

                long long lim = (j ? 9 : s[i] - '0');

                for(long long d = 0; d <= lim; d++){

                    (dp[i + 1][j || d < lim][(d + k) % D] += dp[i][j][k]) %= mod;                    

                }
            }
        }
    }
    long long res = dp[n][0][0] + dp[n][1][0] - 1;
    if(res >= mod)res -= mod;
    if(res < 0)res += mod;
    std::cout << res << std::endl;


}

def solve():
    N = input()
    K = int(input())
    dp = [[[0]*(K+2) for i in range(2)] for j in range(len(N)+1)]
    dp[0][False][0] = 1

    for i in range(len(N)):
        for k in range(K+1):
            dp[i+1][True][k+1] += dp[i][True][k] * 9
            dp[i+1][True][k] += dp[i][True][k]

            if int(N[i]) > 0:
                dp[i+1][True][k+1] += dp[i][False][k] * (int(N[i]) - 1)
                dp[i+1][True][k] += dp[i][False][k]
            
            if int(N[i]) > 0:
                dp[i+1][False][k+1] = dp[i][0][k]
            else:
                dp[i+1][False][k] = dp[i][0][k]
    
    print(dp[-1][False][K] + dp[-1][True][K])

if __name__ == '__main__':
    solve()
N = input()
K = int(input())
n = len(N)
dp = [[[0]*(K+1) for _ in range(2)] for _ in range(n+1)]
dp[0][0][0] = 1

for i in range(1, n+1):
    l = int(N[i-1])
    for k in range(K+1):
        dp[i][1][k] += dp[i-1][1][k]
        if l != 0:
            dp[i][1][k] += dp[i-1][0][k]
        else:
            dp[i][0][k] += dp[i-1][0][k]
        if k-1 >= 0:
            dp[i][1][k] += dp[i-1][1][k-1]*9
            if l != 0:
                dp[i][0][k] += dp[i-1][0][k-1]
                dp[i][1][k] += dp[i-1][0][k-1]*(l-1)
                
print (dp[n][0][K]+dp[n][1][K])
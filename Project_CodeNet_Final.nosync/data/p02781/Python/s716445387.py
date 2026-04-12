N = input()
K = int(input())

digit = len(N)
dp = [[[0]*(K+1) for _ in range(2)] for _ in range(digit)]

di = int(N[0])
dp[0][0][0] = 0
dp[0][0][1] = 1
dp[0][1][0] = 1
dp[0][1][1] = di-1

for i in range(1, digit):
    dp[i][1][0] = 1
    for k in range(1, K+1):
        di = int(N[i])
        if di == 0:
            dp[i][0][k] = dp[i-1][0][k]
            dp[i][1][k] = dp[i-1][1][k] + dp[i-1][1][k-1]*9
        else:
            dp[i][0][k] = dp[i - 1][0][k - 1]
            dp[i][1][k] = dp[i-1][0][k-1]*(di-1)+dp[i-1][0][k]\
                      +dp[i-1][1][k]+dp[i-1][1][k-1]*9


print(dp[-1][0][K]+dp[-1][1][K])
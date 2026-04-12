k = input()
len_k = len(k)
d = int(input())
MOD = 10**9 + 7

dp = [[[0]*d for i in range(len_k+1)] for i in range(2)]
dp[1][0][0] = 1

for i in range(len_k):
    for j in range(d):
        dp[1][i+1][(j+int(k[i])) % d] += dp[1][i][j]
        dp[1][i+1][(j+int(k[i])) % d] %= MOD
        for l in range(int(k[i])):
            dp[0][i+1][(j+l) % d] += dp[1][i][j]
            dp[0][i+1][(j+l) % d] %= MOD
        for l in range(10):
            dp[0][i+1][(j+l) % d] += dp[0][i][j]
            dp[0][i+1][(j+l) % d] %= MOD

print((dp[0][-1][0] + dp[1][-1][0] - 1) % MOD)
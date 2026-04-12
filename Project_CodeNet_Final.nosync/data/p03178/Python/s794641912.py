K = input()
D = int(input())
L = len(K)
MOD = 10**9 + 7

dp = [[[0]*D for _ in range(2)] for _ in range(L+1)]
# dp[i][j][d] = num of "up to i-th, j = less than flag, d mod = d"
dp[0][0][0] = 1

for i in range(1, L+1):
    a = int(K[i-1])
    for d in range(D):
        dp[i][0][(d+a)%D] += dp[i-1][0][d]
        dp[i][0][(d+a)%D] %= MOD
        for b in range(10):
            dp[i][1][(d+b)%D] += dp[i-1][1][d] + (b<a)*dp[i-1][0][d]
            dp[i][1][(d+b)%D] %= MOD

print((dp[L][0][0] + dp[L][1][0] - 1)%MOD)
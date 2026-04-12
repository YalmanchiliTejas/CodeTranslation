K = input()
L = len(K)
D = int(input())
MOD = 10**9+7

dp = [[[0,0] for _ in range(D)] for _ in range(L+1)]
dp[0][0][0] = 1
for i,c in enumerate(K):
    c = int(c)
    for x in range(D):
        for d in range(10):
            y = (x+d)%D
            dp[i+1][y][1] += dp[i][x][1]
            dp[i+1][y][1] %= MOD
            if d > c: continue
            dp[i+1][y][int(d<c)] += dp[i][x][0]
            dp[i+1][y][int(d<c)] %= MOD
print((sum(dp[-1][0]) - 1) % MOD)
K = input()
l = len(K)
D = int(input())
MOD = 10**9+7

dp = [[[0]*D for _ in range(2)] for _ in range(l+1)]
dp[0][0][0] = 1

for i in range(l):
    for j in range(D):
        nd = int(K[i])
        for d in range(10):
            dp[i+1][1][(j+d)%D] += dp[i][1][j%D]%MOD #smaller->smaller
            if d < nd:
                dp[i+1][1][(j+d)%D] += dp[i][0][j%D]%MOD #exact->smaller
        dp[i+1][0][(j+int(K[i]))%D] += dp[i][0][j%D]%MOD #exact->exact


ans = (dp[l][0][0] + dp[l][1][0]-1) % MOD
print(ans)
K = input()
D = int(input())

MOD = 10**9+7
N = len(K)

# dp[i][j][k] := 上から i まで見て余りが j であり、
# k = 0 -> K ちょうど
# k = 1 -> K より小さい
# ようなものの数
dp = [[[0]*2 for _ in range(D)] for _ in range(N+1)] 
dp[0][0][0] = 1
for i in range(N):
    k = int(K[i])
    for j in range(D):
        dp[i+1][(j+k)%D][0] = dp[i][j][0]
        dp[i+1][(j+k)%D][0] %= MOD
        for d in range(10):
            dp[i+1][(j+d)%D][1] += dp[i][j][1]
            if d < k:
                dp[i+1][(j+d)%D][1] += dp[i][j][0]
            dp[i+1][(j+d)%D][1] %= MOD

print((dp[N][0][0]+dp[N][0][1]-1)%MOD)
mod = 10**9+7
K = input()
D = int(input())
N = len(K)
dp = [[0] * D for i in range(N)]
for i in range(int(K[0])):
    dp[0][i%D] += 1
tight = int(K[0])%D
for i in range(1, N):
    for j in range(D):
        for k in range(10):
            dp[i][j] += dp[i-1][(j-k)%D]
            dp[i][j] %= mod
    for k in range(int(K[i])):
        dp[i][(tight+k)%D] += 1
    tight = (tight+int(K[i]))%D
print((dp[N-1][0]+(tight==0)-1)%mod)

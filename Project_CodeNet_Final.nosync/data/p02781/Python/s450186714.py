N = input()
K = int(input())

L = len(N)
dp = [[[0]*(K+2) for _ in range(2)] for _ in range(L+1)]
dp[0][0][0] = 1

for i in range(1,L+1):
    a = int(N[i-1])
    for k in range(K+1):
        dp[i][0][k] += dp[i-1][0][k] if a==0 else dp[i-1][0][k-1]
        dp[i][1][k] += dp[i-1][1][k-1]*9 + dp[i-1][1][k]
        if a>0:
            dp[i][1][k] += dp[i-1][0][k-1]*(a-1) + dp[i-1][0][k]

print(dp[L][0][K]+dp[L][1][K])
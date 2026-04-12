K = int(input())
D = int(input())
mod = 10**9 + 7

dp = [[[0] * D for _ in range(2)] for _ in range(len(str(K))+1)]
dp[0][0][0] = 1

for i in range(len(str(K))):
    N = int(str(K)[i])
    for j in range(2):
        for k in range(D):
            for n in range((9 if j == 1 else N) + 1):
                dp[i+1][j or n < N][(k+n%D)%D] += dp[i][j][k]%mod

print((dp[-1][0][0]+dp[-1][1][0]-1)%mod)

N = input()
K = int(input())
dp = [[[0]*(2) for _ in range(K+1)] for _ in range(len(N)+1)]
dp[0][0][0] = 1

for i in range(len(N)) :
    for k in range(K+1) :
        for j in range(2) :
            n = int(N[i])
            for d in range(10) :
                nk = k
                nj = j
                if d != 0:
                    nk += 1
                if nk > K:
                    continue
                if j == 0:
                    if d > n:
                        continue
                    if d < n:
                        nj = 1
                dp[i+1][nk][nj] += dp[i][k][j]

ans = dp[len(N)][K][0] + dp[len(N)][K][1]

print(ans)

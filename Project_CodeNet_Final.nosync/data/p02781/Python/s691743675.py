N = str(input())
K = int(input())

dp = [[[0] * 2 for _ in range(4)] for _ in range(105)]
dp[0][0][0] = 1

n = len(N)
for i in range(n):
    nd = int(N[i])
    for j in range(4):
        for k in range(2):
            for d in range(10):
                ni = i + 1
                nj = j
                nk = k
                if d != 0:
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]

print (dp[n][K][0] + dp[n][K][1])
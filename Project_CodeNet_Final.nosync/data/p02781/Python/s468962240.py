import math

N = int(input())
K = int(input())
l = len(str(N))

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(102)]
dp[0][0][0] = 1

for i in range(l):
    for j in range(4):
        for k in range(2):
            for d in range(10):
                nd = int(str(N)[i])
                ni = i + 1
                nj = j
                nk = k
                if d > 0:
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]

print(dp[l][K][0] + dp[l][K][1])


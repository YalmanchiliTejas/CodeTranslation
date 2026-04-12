dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(105)]

s = input()
n = len(s)
K = int(input())

dp[0][0][0] = 1
for i in range(n):
    for j in range(4):
        for k in range(2):
            nd = int(s[i])
            for d in range(10):
                ni, nj, nk = i + 1, j, k
                if d != 0:
                    nj += 1
                if nj > K:
                    continue
                if 0 == k:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]
print(dp[n][K][0] + dp[n][K][1])

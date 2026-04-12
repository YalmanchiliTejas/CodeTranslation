s = str(input())
K = int(input())

n = len(s)

dp = [[[0]*2 for i in range(4)] for j in range(105)]
dp[0][0][0] = 1

for i in range(n):
    for j in range(4):
        for k in range(2):
            nd = int(s[i])
            for d in range(10):
                ni = i+1
                nj = j
                nk = k
                if d != 0:
                    nj += 1
                if k == 0:
                    if d > nd:
                        continue
                    elif d < nd:
                        nk = 1
                    else:
                        pass
                if 0 <= nj <= 3:
                    dp[ni][nj][nk] += dp[i][j][k]

print(dp[n][K][0] + dp[n][K][1])
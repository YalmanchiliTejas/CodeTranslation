S = list(input())
K = int(input())
N = len(S)
dp = [[[0] * 2 for i in range(4)] for i in range(105)]
#print(dp)
dp[0][0][0] = 1
for i in range(N):
    nd = int(S[i])
    for j in range(4):
        for k in range(2):
            for d in range(10):
                ni = i+1
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
#print(dp)
print(dp[N][K][0] + dp[N][K][1])

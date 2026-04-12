S = input()
K = int(input())
N = len(S)

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(105)]
dp[0][0][0] = 1

for i in range(N):
    for j in range(4):
        for k in range(2):
            nd = int(S[i])
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

print(dp[N][K][0] + dp[N][K][1])

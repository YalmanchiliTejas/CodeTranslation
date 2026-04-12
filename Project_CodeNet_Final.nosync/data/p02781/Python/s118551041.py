s = input()
K = int(input())
N = len(s)
dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(105)]
dp[0][0][0] = 1
for i in range(N):
    for j in range(4):
        for k in range(2):
            nd = ord(s[i]) - ord('0')
            for d in range(10):
                ni, nj, nk = i + 1, j, k
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
ans = dp[N][K][0] + dp[N][K][1]
print(ans)

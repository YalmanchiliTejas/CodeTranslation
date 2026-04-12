s = input()
K = int(input())

dp = [[[0 for i in range(2)] for j in range(4)] for k in range(105)]

n = len(s)

dp[0][0][0] = 1
# print(dp)
for i in range(n):
    for j in range(4):
        for k in range(2):
            nd = int(s[i])  # 今の桁の数
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
# print(dp)
ans = dp[n][K][0] + dp[n][K][1]
print(ans)


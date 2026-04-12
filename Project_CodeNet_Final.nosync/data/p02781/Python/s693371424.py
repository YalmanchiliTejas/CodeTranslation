n = list(map(int, list(input())))
k = int(input())
le = len(n)
dp = [[[0] * (le + 2) for _ in range(2)] for _ in range(le + 1)]
dp[0][0][0] = 1
for i in range(1, le + 1):
    for j in range(2):
        for s in range(le + 1):
            m = 10
            if j == 0:
                m = n[i - 1] + 1
            for t in range(m):
                x, y = 1, s
                if j == 0 and t == m - 1:
                    x = 0
                if not t == 0:
                    y += 1
                dp[i][x][y] += dp[i - 1][j][s]
ans = dp[le][0][k] + dp[le][1][k]
print(ans)
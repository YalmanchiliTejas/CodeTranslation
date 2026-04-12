s = input()
n = len(s)
k = int(input())
dp = [[[0 for _ in range(2)] for _ in range(k + 1)] for _ in range(n + 1)]
dp[0][0][0] = 1

for a in range(n):
    for b in range(k + 1):
        for c in range(2):
            nd = int(s[a])
            for d in range(10):
                na, nb, nc = a + 1, b, c
                if 0 != d:
                    nb += 1
                if k < nb:
                    break
                if 0 == nc:
                    if nd > d:
                        nc = 1
                    if nd < d:
                        break
                dp[na][nb][nc] += dp[a][b][c]
print(sum(dp[-1][-1]))

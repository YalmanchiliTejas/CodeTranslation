n = str(input())
k = int(input())
m = len(n)
dp = [[[0,0] for __ in range(k+2)] for _ in range(m+1)]
dp[0][0][0] = 1
for i in range(m):
    d = int(n[i])
    for j in range(k+1):
        for s in range(2):
            for c in range(10):
                if (not s ) and c>d:
                    continue
                dp[i+1][j+(c!=0)][s or (c<d)] += dp[i][j][s]
print(dp[m][k][0]+dp[m][k][1])
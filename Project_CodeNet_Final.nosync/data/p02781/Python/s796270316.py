n = input()
k = len(n) - int(input())
if k < 0:
    print(0)
    exit()

dp = [[[0] * 2 for _ in range(k + 1)] for _ in range(len(n)+1)]

dp[0][0][1] = 1

for i in range(len(n)):
    if n[i] == "0":
        for j in range(k):
            dp[i + 1][j + 1][0] = dp[i][j][0]
            dp[i + 1][j + 1][1] = dp[i][j][1]
        for j in range(k+1):
            dp[i + 1][j][0] += dp[i][j][0] * 9
    else:
        for j in range(k):
            dp[i + 1][j + 1][0] = dp[i][j][0] + dp[i][j][1]
        for j in range(k+1):
            dp[i + 1][j][0] += dp[i][j][0] * 9+dp[i][j][1] * (int(n[i])-1)
            dp[i + 1][j][1] += dp[i][j][1]
print(sum(dp[-1][-1]))

n = input()
k = int(input())

digit_n = len(n)

# dp[x][j][i]: x:n未満か否か, j:0でない数字の数, i:桁
dp = [[[0] * (digit_n + 1) for _ in range(k+1)] for _ in range(2)]
dp[0][0][0] = 1

for i in range(digit_n):
    m = int(n[i])
    for j in range(k+1):
        dp[1][j][i+1] = dp[1][j][i]
        if j > 0:
            dp[1][j][i+1] += dp[1][j-1][i] * 9
    for j in range(k+1):
        if m == 0:
            dp[0][j][i+1] = dp[0][j][i]
        else:
            dp[1][j][i+1] += dp[0][j][i]
            if j > 0:
                dp[1][j][i+1] += dp[0][j-1][i] * (m-1)
                dp[0][j][i+1] = dp[0][j-1][i]

print(dp[0][k][-1] + dp[1][k][-1])

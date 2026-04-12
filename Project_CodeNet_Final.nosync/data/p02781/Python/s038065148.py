n = int(input())

k = int(input())

keta = len(str(n))

dp = [[[0 for j in range(k+2)] for _ in range(2)]  for i in range(keta)]

s = str(n)

#dp[何桁目か][未満フラグ 0 = 未満][ゼロ以外のの個数]

x = int(s[0])
if x == 1:
    dp[0][1][0] = 1
else:
    dp[0][1][0] += 1
    dp[0][0][0] += x - 1


for index, c in enumerate(s[1:]):
    i = index + 1
    x = int(c)
    dp[i][0][0] += 9
    for j in range(k+1):
        dp[i][0][j] += dp[i - 1][0][j]
        if x == 0:
            dp[i][1][j] += dp[i - 1][1][j]
            dp[i][0][j + 1] += dp[i - 1][0][j] * 9
        elif x:
            dp[i][1][j + 1] += dp[i - 1][1][j]
            dp[i][0][j]     += dp[i - 1][1][j]
            dp[i][0][j + 1] += dp[i - 1][0][j] * 9
            dp[i][0][j + 1] += dp[i - 1][1][j] * (x - 1)
    # print(sum(dp[i][0]) + sum(dp[i][1]))
    # print(s[:index + 2])
    # print(dp)




print(dp[-1][0][k-1] + dp[-1][1][k-1])

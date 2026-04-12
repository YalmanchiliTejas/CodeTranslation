n = input()
k = int(input())

l = len(n)
dp = [[[0 for _ in range(k+1)] for j in range(2)] for i in range(l+1)]
dp[0][0][0] = 1

for i in range(l):
    for j in range(2):
        for m in range(k+1):
            ni = int(n[i])
            if j == 0:
                for num in range(ni+1):
                    if num == ni:
                        if ni == 0:
                            dp[i+1][0][m] += dp[i][j][m]
                        else:
                            if m+1 <= k:
                                dp[i+1][0][m+1] += dp[i][j][m]
                    else:
                        if num == 0:
                            dp[i+1][1][m] += dp[i][j][m]
                        else:
                            if m+1 <= k:
                                dp[i+1][1][m+1] += dp[i][j][m]
            else:
                for num in range(10):
                    if num == 0:
                        dp[i+1][1][m] += dp[i][j][m]
                    else:
                        if m+1 <= k:
                            dp[i+1][1][m+1] += dp[i][j][m]



print(dp[l][0][k] + dp[l][1][k])
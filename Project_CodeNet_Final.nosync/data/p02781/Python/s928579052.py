N = input()
K = int(input())

# dp[i][j][smaller] := i 桁目まで追加して, 0の個数がj個の数字の個数
keta = len(N)

dp = [[[0] * 2 for _ in range(K+3)] for __ in range(keta + 1)]

dp[0][0][0] = 1

for i in range(keta):
    now_digit = int(N[i])
    for k in range(10):
        for j in range(K+1):
            if k == 0:
                if k < now_digit:
                    dp[i+1][j][1] += dp[i][j][1] + dp[i][j][0]
                elif k == now_digit:
                    dp[i+1][j][1] += dp[i][j][1]
                    dp[i+1][j][0] += dp[i][j][0]
                else:
                    dp[i+1][j][1] += dp[i][j][1]
            else:
                if k < now_digit:
                    dp[i+1][j+1][1] += dp[i][j][1] + dp[i][j][0]
                elif k == now_digit:
                    dp[i+1][j+1][1] += dp[i][j][1]
                    dp[i+1][j+1][0] += dp[i][j][0]
                else:
                    dp[i+1][j+1][1] += dp[i][j][1]
print(dp[-1][K][0] + dp[-1][K][1])
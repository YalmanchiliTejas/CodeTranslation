N = input()
K = int(input())

dp = [[[0]*2 for k in range(K+1)] for i in range(len(N)+1)]

# dp[i][x][flg]: 上からi桁目までが確定した段階で、0でない数字がx個あるような数字の個数
#    flg 0: 今作成している数字がN未満であることが確定していない
#    flg 1: 今作成している数字がN未満であることが確定している
dp[0][0][0] = 1

for i in range(len(N)):
    num = int(N[i])  # Nの上からi桁目の数字
    for x in range(K+1):
        if num == 0:
            dp[i+1][x][0] += dp[i][x][0]
            dp[i+1][x][1] += dp[i][x][1]
            if x >= 1:
                dp[i+1][x][1] += dp[i][x-1][1]*9
        else:  # num != 0
            dp[i+1][x][1] += dp[i][x][0] + dp[i][x][1]
            if x >= 1:
                dp[i+1][x][0] += dp[i][x-1][0]
                dp[i+1][x][1] += dp[i][x-1][0]*(num-1) + dp[i][x-1][1]*9
    # print(i, dp[i+1])


print(sum(dp[len(N)][K]))

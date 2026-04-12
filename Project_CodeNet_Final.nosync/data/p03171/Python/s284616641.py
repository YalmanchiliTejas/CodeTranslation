N = int(input())
a = list(map(int, input().split()))
dp = [[-1 for i in range(3010)] for j in range(3010)]
for i in range(3010):
    dp[i][i] = 0
for len in range(1, N+1):
    for i in range(N - len + 1):
        j = i + len
        if (N - len) % 2 == 0: # 前が誰の手番であったか
            # 先手番
            dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]) # lenが1つ短いものから遷移

        else:
            # 後手番
            dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1])
print(dp[0][N])
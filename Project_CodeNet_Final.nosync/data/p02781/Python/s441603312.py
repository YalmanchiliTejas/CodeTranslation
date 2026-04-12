n = input()
k = int(input())

dp = [[[0,0] for i in range(len(n)+1)] for j in range(len(n)+1)]

# print(dp)
num_d = len(n)

dp[0][0][0] = 1

for i in range(len(n)):
    num = int(n[i])

    if num == 0:
        for j in range(num_d):
            dp[i+1][j+1][0] = dp[i][j][0]
            dp[i+1][j+1][1] += dp[i][j][1]

        for j in range(num_d+1):
            dp[i+1][j][1] += dp[i][j][1]*9

    else:
        for j in range(num_d):
            dp[i+1][j][0] = dp[i][j][0]

        for j in range(num_d+1):
            dp[i+1][j][1] += dp[i][j][0]*(num-1)
            dp[i+1][j][1] += dp[i][j][1]*9

        for j in range(num_d):
            dp[i+1][j+1][1] += dp[i][j][0] + dp[i][j][1]

# print(dp[-1])
if num_d < k:
    print(0)
else:
    print(sum(dp[-1][num_d-k]))
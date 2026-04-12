n = input()
k = int(input())
l = len(n)

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(l)]

dp[0][1][0] = int(n[0])-1
dp[0][1][1] = 1

for i in range(1, l):

    dp[i][1][0] = dp[i-1][1][0] + 9
    dp[i][2][0] = dp[i-1][2][0] + 9 * dp[i-1][1][0]
    dp[i][3][0] = dp[i-1][3][0] + 9 * dp[i-1][2][0]

    if int(n[i]) == 0:
        dp[i][1][1] = dp[i-1][1][1]

    elif dp[i-1][1][1] == 1:
        dp[i][2][1] = 1
        dp[i][2][0] += int(n[i])-1
        dp[i][1][0] += 1

    elif dp[i-1][2][1] == 1:
        dp[i][3][1] = 1
        dp[i][3][0] += int(n[i])-1
        dp[i][2][0] += 1

    elif dp[i-1][3][1] == 1:
        dp[i][3][0] += 1

print(sum(dp[-1][k]))
s = input()
k = int(input())
l = len(s)
dp = [[[0 for i in range(k+1)] for j in range(2)] for m in range(l+1)]
dp[0][0][0] = 1
for i in range(l):
    for x in range(k+1):
        if s[i] == "0":
            dp[i+1][0][x] += dp[i][0][x]
        else:
            if x < k:
                dp[i+1][0][x+1] += dp[i][0][x]
            dp[i+1][1][x] += dp[i][0][x]
        for j in range(1, int(s[i])):
            if x < k:
                dp[i+1][1][x+1] += dp[i][0][x]
        dp[i+1][1][x] += dp[i][1][x]
        for j in range(1, 10):
            if x < k:
                dp[i+1][1][x+1] += dp[i][1][x]
print(dp[-1][0][-1] + dp[-1][1][-1])
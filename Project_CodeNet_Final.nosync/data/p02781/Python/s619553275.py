n, k = int(input()), int(input())
l = len(str(n))
s = [0] + list(map(int, str(n)))
if k > l: print(0); exit()

dp = [[[0] * 2 for _ in range(k+1)] for _ in range(l+1)]
dp[0][0][1] = 1

for dig in range(l):
    for i in range(k+1):
        dp[dig+1][i][0] += dp[dig][i][0]
        dp[dig+1][i][1 if s[dig+1] == 0 else 0] += dp[dig][i][1]
        if i < k:
            dp[dig+1][i+1][0] += dp[dig][i][0] * 9
            if s[dig+1] > 0:
                dp[dig+1][i+1][1] += dp[dig][i][1]
                dp[dig+1][i+1][0] += dp[dig][i][1] * (s[dig+1]-1)

print(dp[l][k][0] + dp[l][k][1])

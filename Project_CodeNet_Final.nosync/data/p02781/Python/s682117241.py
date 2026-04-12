import sys
input = sys.stdin.readline
n = input().strip()
k = int(input())
l = len(n)

dp = [[[0] * (k+1) for _ in range(2)] for _ in range(l+1)]
dp[0][1][0] = 1
for i, s in enumerate(n, start=1):
    s = int(s)
    for j in range(10):
        if j == 0:
            if j < s:
                for x in range(k+1):
                    dp[i][0][x] += dp[i-1][0][x] + dp[i-1][1][x]
            elif j == s:
                for x in range(k+1):
                    for y in range(2):
                        dp[i][y][x] += dp[i-1][y][x]
        elif j < s:
            for x in range(k):
                dp[i][0][x+1] += dp[i-1][0][x] + dp[i-1][1][x]
        elif j == s:
            for x in range(k):
                for y in range(2):
                    dp[i][y][x+1] += dp[i-1][y][x]
        else:
            for x in range(k):
                dp[i][0][x+1] += dp[i-1][0][x]
print(dp[-1][0][k] + dp[-1][1][k])
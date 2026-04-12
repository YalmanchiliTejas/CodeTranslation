import sys

sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline().rstrip()

N = list(map(int, input()))
K = int(input())

# dp[i][j][0] ... i + 1 digits, j non-zero digits, maybe ok
# dp[i][j][1] ... i + 1 digits, j non-zero digits, must be ok

dp = [[[0] * 2 for _ in range(K + 1)] for _ in range(len(N))]

for i in range(len(N)):
    for j in range(K + 1):
        if i == 0:
            dp[i][1][0] = 1
            dp[i][0][1] = 1
            dp[i][1][1] = N[0] - 1
        else:
            if j == 0:
                dp[i][j][1] = dp[i - 1][j][1]
            else:
                if N[i] == 0:
                    dp[i][j][0] = dp[i - 1][j][0]
                    dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 1][1] * 9
                else:
                    dp[i][j][0] = dp[i - 1][j - 1][0]
                    dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 1][1] * 9 + dp[i - 1][j - 1][0] * (N[i] - 1) + dp[i - 1][j][0]

print(sum(dp[len(N) - 1][K]))
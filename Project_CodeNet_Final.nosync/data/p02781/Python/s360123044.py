from sys import stdin

N = stdin.readline().rstrip()
K = int(stdin.readline().rstrip())

N = N[::-1]

dp = [[0] * len(N) for i in range(3)]

dp[0][0] = int(N[0])

for i in range(1, len(N)):
    if N[i] == '0':
        dp[0][i] = dp[0][i - 1]
    else:
        dp[0][i] = int(N[i]) + 9 * i

for i in range(1, len(N)):
    if N[i] == '0':
        dp[1][i] = dp[1][i - 1]
    else:
        dp[1][i] = dp[0][i - 1] + 9 * 9 * i * (i - 1)  // 2 + 9 * i * (int(N[i]) - 1)

for i in range(2, len(N)):
    if N[i] == '0':
        dp[2][i] = dp[2][i - 1]
    else:
        dp[2][i] = dp[1][i - 1] + 9 * 9 * 9 * i * (i - 1) * (i - 2) // 6 + 9 * 9 * i * (i - 1) // 2 * (int(N[i]) - 1)

print(dp[K - 1][len(N) - 1])
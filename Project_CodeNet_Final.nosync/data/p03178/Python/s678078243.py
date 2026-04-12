k = input()
d = int(input())

mod = 10 ** 9 + 7

dp = [[0] * d for _ in range(2)]
dp[1][0] = 1

for i in k:
    i = int(i)
    dp2 = [[0] * d for _ in range(2)]

    for j in range(d):
        dp2[1][(j + i) % d] += dp[1][j]

    for j in range(d):
        for k in range(i):
            dp2[0][(j + k) % d] += dp[1][j]

    for j in range(d):
        for k in range(10):
            dp2[0][(j + k) % d] += dp[0][j]

    dp = [[j % mod for j in k] for k in dp2]

print((dp[0][0] + dp[1][0] - 1) % mod)

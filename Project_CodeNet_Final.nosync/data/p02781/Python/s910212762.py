from itertools import product
n = input()
k = int(input())
dp = [[[0] * (k + 2) for _ in range(2)] for _ in range(len(n) + 1)]
dp[0][0][0] = 1
for i, j, l in product(range(len(n)), range(2), range(k + 1)):
    for x in range(10):
        if j == 0 and x > int(n[i]):
            continue
        dp[i + 1][0 if j == 0 and x == int(n[i]) else 1][l + 1 if x != 0 else l] += dp[i][j][l]
print(dp[len(n)][0][k] + dp[len(n)][1][k])
n = int(input())
a = list(map(int, input().split()))

dp = [dict() for _ in range(n)]

dp[0][0] = 0
dp[0][1] = a[0]
dp[1][0] = 0
dp[1][1] = max(a[0], a[1])

import math
for i in range(2, n):
    k1 = int(math.ceil((i + 1) / 2))
    k2 = k1 - 1

    if i % 2 == 0:
        dp[i][k1] = dp[i-2][k1-1] + a[i]
    else:
        dp[i][k1] = max(dp[i-1][k1], dp[i-2][k1-1] + a[i])

    dp[i][k2] = max(dp[i-1][k2], dp[i-2][k2-1] + a[i])

print(dp[-1][n // 2])

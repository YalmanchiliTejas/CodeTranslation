from sys import stdin

input = stdin.readline

n = int(input())
a = [int(x) for x in input().split()]
dp = [[0] * 3 for x in range(n)]

dp[0][0] = a[0]
dp[1][1] = a[1]


if n > 2:
    dp[2][0] = a[0] + a[2]
    dp[2][2] = a[2]

if n > 3:
    dp[3][1] = max(a[0] + a[3], a[1] + a[3])

for x in range(4, n):
    if x % 2 == 0:
        dp[x][0] = dp[x - 2][0] + a[x]
    dp[x][1] = max(dp[x - 2][1] + a[x], dp[x - 3][0] + a[x])
    dp[x][2] = max(dp[x - 2][2] + a[x], dp[x - 3][1] + a[x], dp[x - 4][0] + a[x])


if n % 2 == 0:
    print(max(dp[-2][0], dp[-1][1]))
else:
    print(max(dp[-3][0], dp[-2][1], dp[-1][2]))
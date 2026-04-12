from collections import defaultdict

n = int(input())
a = list(map(int, input().split()))
INF = 10 ** 18

dp = defaultdict(lambda: -INF)
dp[(0, 0, 0)] = 0

for i, e in enumerate(a, 1):
    for j in range((i - 1) // 2, (i + 1) // 2 + 1):
        dp[(i, j, 0)] = max(dp[(i-1, j, 0)], dp[(i-1, j, 1)])
        dp[(i, j, 1)] = dp[(i-1, j-1, 0)] + e

ans = max(dp[(n, n//2, 0)], dp[(n, n//2, 1)])
print(ans)

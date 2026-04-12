n, m = map(int, input().split())
list_MAP = [[0]*n for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    list_MAP[a-1][b-1] = 1
    list_MAP[b-1][a-1] = 1

dp = [[0]*n for _ in range(1<<n)]
dp[1][0] = 1
for num in range(1<<n):
    for v in range(n):
        if num & (1<<v) == 0:
            continue
        sub = num ^ (1<<v)

        for u in range(n):
            if sub & (1<<u) and list_MAP[v][u]:
                dp[num][v] += dp[sub][u]
ans = sum(dp[(1 << n) - 1])
print(ans)
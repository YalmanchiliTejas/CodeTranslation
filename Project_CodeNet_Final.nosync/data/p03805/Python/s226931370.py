n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

adj = [[] for _ in range(n)]
for a, b in ab:
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

dp = [[0] * n for _ in range(1 << n)]
dp[1][0] = 1

for i in range(1 << n):
    for u in range(n):
        for v in adj[u]:
            if i >> v & 1 == 0:
                nxt = i + (1 << v)
                dp[nxt][v] += dp[i][u]

print(sum(dp[-1]))

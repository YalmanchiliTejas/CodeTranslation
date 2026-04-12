n, m = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    g[a].append(b)
    g[b].append(a)

dp = [[0]*n for i in range(2**n)]
dp[1][0] = 1

for s in range(2**n):
    for v in range(n):
        if (s >> v) & 1:
            # t = s - {v}
            t = s ^ (1 << v)
            for u in g[v]:
                if (t >> u) & 1:
                    dp[s][v] += dp[t][u]
#print(dp)
ans = 0
for v in range(n):
    ans += dp[-1][v]
print(ans)
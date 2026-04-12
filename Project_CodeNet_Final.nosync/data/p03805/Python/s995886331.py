N, M = map(int, input().split())

g = {}
n_path = 0
for i in range(N):
    g[i] = set()
for _ in range(M):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    g[a].add(b)
    g[b].add(a)

dp = [[0 for _ in range(N)] for _ in range(1 << N)]
dp[1][0] = 1

for bit in range(1 << N):
    for v in range(N):

        if bit & (1 << v) is False:
            continue

        sub = bit ^ (1 << v)

        for u in range(N):
            if (v in g[u]) and (sub & (1 << u)):
                dp[bit][v] += dp[sub][u]

print(sum(dp[-1]))

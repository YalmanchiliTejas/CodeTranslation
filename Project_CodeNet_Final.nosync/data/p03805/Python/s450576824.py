from collections import defaultdict

N, M = map(int, input().split())
adjacent = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adjacent[a].append(b)
    adjacent[b].append(a)

dp = defaultdict(int)
dp[(1, 0)] = 1
for S in range(1 << N):
    for v in range(N):
        if S & (1 << v) == 0:
            continue
        sub = S ^ (1 << v)
        for u in adjacent[v]:
            if sub & (1 << u):
                dp[(S, v)] += dp[(sub, u)]
print(sum(dp[((1 << N) - 1, u)] for u in range(1, N)))

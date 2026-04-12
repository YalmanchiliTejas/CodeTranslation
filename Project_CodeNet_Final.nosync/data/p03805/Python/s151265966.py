N, M = map(int, input().split())
E = [tuple(map(int, input().split())) for _ in range(M)]

graph = [[0 for j in range(N)] for i in range(N)]

for e in E:
    graph[e[0] - 1][e[1] - 1] = 1
    graph[e[1] - 1][e[0] - 1] = 1

res = 0

dp = [[0 for j in range(N)] for i in range(2**N)]
dp[1][0] = 1

for i in range(2**N):
    for j in range(N):
        for k in range(N):
            if not (i >> k & 1) and graph[j][k]:
                dp[(i)|(1 << k)][k] += dp[i][j]

print(sum(dp[-1]))
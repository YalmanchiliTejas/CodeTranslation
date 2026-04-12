import numpy as np

N, M = map(int, input().split())
edge = [[] for i in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append(b)
    edge[b].append(a)
# print(*edge, sep='\n')

# N, M = 3, 3
# edge = [[1, 2], [0, 2], [0, 1]]


def dfs(v):
    if sum(visited) == N:
        return 1

    res = 0
    for i in edge[v]:
        if visited[i] == 1:
            continue
        visited[i] = 1
        res += dfs(i)
        visited[i] = 0
    return res


visited = [0] * N

visited[0] = 1
ans = dfs(0)

print(ans)

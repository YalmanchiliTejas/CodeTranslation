import sys
sys.setrecursionlimit(10 ** 6)

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    graph[a].append(b)
    graph[b].append(a)
def dfs(cur, visited):
    if visited == (1 << N) - 1:
        return 1
    res = 0
    for to in graph[cur]:
        if not visited & (1 << to):
            res += dfs(to, visited | (1 << to))
    return res
print(dfs(0, 1))

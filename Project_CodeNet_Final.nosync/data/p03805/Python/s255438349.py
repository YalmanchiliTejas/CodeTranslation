import sys
sys.setrecursionlimit(10**6)

cnt = 0
def dfs(graph, v, seen):
    if not False in seen:
        global cnt
        cnt += 1
        return

    for i in graph[v]:
        if seen[i]:
            continue
        seen[i] = True
        dfs(graph, i, seen)
        seen[i] = False
    return cnt

n, m = map(int, input().split())
graph = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
    seen = [False for _ in range(n)]
    seen[0] = True



print(dfs(graph, 0, seen))
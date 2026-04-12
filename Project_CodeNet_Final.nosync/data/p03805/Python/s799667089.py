import pprint

def dfs(v, n, visited):
    all_visited = True

    for i in range(n):
        if visited[i] is False:
            all_visited = False

    if all_visited:
        return 1

    ret = 0
    for i in range(n):
        if edges[v][i] is False:
            continue
        if visited[i]:
            continue

        visited[i] = True
        ret += dfs(i, n, visited)
        visited[i] = False
    return ret


N, M = tuple(map(int, input().split()))
nmax = 8
edges = [[False] * nmax for _ in range(nmax)]
for _ in range(M):
    A, B = tuple(map(int, input().split()))
    edges[A-1][B-1] = True
    edges[B-1][A-1] = True

visited = [False] * nmax
visited[0] = True
print(dfs(0, N, visited))

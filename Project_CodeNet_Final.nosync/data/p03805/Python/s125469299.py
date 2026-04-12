N, M = [int(i) for i in input().split()]
E = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = [int(i) for i in input().split()]
    E[a].append(b)
    E[b].append(a)

visited = [False] * (N + 1)

def dfs(src, count):
    if count == N:
        return 1

    visited[src] = True
    result = 0
    for dst in E[src]:
        if not visited[dst]:
            result += dfs(dst, count + 1)
    visited[src] = False

    return result

print(dfs(1, 1))
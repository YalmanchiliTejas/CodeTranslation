N, M = map(int, input().split())
graph = [[] for i in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)


def dfs(now, prev, visited):
    visited.append(now)
    if len(visited) == N:
        return 1

    ret = 0
    for edge in graph[now]:
        if edge == prev:
            continue
        if edge in visited:
            continue

        ret += dfs(edge, prev, visited[:])

    return ret


print(dfs(0, -1, []))

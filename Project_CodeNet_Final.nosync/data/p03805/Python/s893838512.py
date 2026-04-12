N, M = map(int, input().split())
adjacent = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adjacent[a].append(b)
    adjacent[b].append(a)


def dfs(visited, v):
    if visited == (1 << N) - 1:
        return 1

    ans = 0
    for u in adjacent[v]:
        if visited >> u & 1 == 1:
            continue
        visited += 1 << u
        ans += dfs(visited, u)
        visited -= 1 << u
    return ans


print(dfs(1, 0))

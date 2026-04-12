N, M = [int(v) for v in input().split()]
tbl = [[0] * (N + 1) for _ in range(N + 1)]


def dfs(v, visited):
    if len(visited) == N:
        return 1

    ans = 0
    for i in range(1, N + 1):
        if i == v: continue
        if tbl[i][v] == 1 and i not in visited:
            visited.append(i)
            ans += dfs(i, visited)
            visited.pop()
    return ans


for _ in range(M):
    a, b = [int(v) for v in input().split()]
    tbl[a][b] = 1
    tbl[b][a] = 1

paths = [1, ]
print(dfs(1, paths))
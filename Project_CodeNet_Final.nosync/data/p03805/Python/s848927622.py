def find(n, N, E, visited):
    visited = visited | {n}
    if len(visited) == N:
        return 1
    cnt = 0
    for e in E[n]:
        if e not in visited:
            cnt += find(e, N, E, visited)
    return cnt

N, M = [int(x) for x in input().split()]
E = {}

for i in range(M):
    x, y = [int(x) for x in input().split()]
    E[x] = E.get(x, set()) | {y}
    E[y] = E.get(y, set()) | {x}

print(find(1, N, E, {1}))



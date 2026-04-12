
import sys
sys.setrecursionlimit(10**5)

N,M = map(int, input().split())

es = [[] for _ in range(N)]

for _ in range(M):
    a,b = map(int, input().split())
    es[a-1].append(b-1)
    es[b-1].append(a-1)


def solve(visited, node):
    visited[node] = True
    if all(visited):
        return 1

    cnt = 0
    for b in es[node]:
        if not visited[b]:
            cnt += solve(visited[:], b)

    return cnt


vis = [False] * N
ans = solve(vis, 0)
print(ans)
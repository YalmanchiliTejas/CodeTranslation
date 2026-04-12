N, M = map(int, input().split())
adjs = [list() for _ in range(N)]
vis = [False for _ in range(N)]

def dfs(v, cnt):
    if vis[v]:
        return 0
    vis[v] = True
    cnt += 1
    ka = 0
    for x in adjs[v]:
        ka += dfs(x, cnt)
    if cnt == N:
        ka = 1
    vis[v] = False
    return ka

for _ in range(M):
    a, b = map(int, input().split())
    adjs[a-1].append(b-1)
    adjs[b-1].append(a-1)
print(dfs(0, 0))
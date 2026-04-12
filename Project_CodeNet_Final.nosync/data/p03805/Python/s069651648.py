N,M = map(int,input().split())
ad = [[0]*N for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    a -= 1; b -= 1
    ad[a][b] = 1
    ad[b][a] = 1

ans = 0

def dfs(v=0,visited=[0]*N):
    visited[v] = 1
    if all(visited):
        global ans
        ans += 1
        return
    for nv, bit in enumerate(ad[v]):
        if bit == 0 or visited[nv] == 1: continue
        dfs(nv,visited[:])

dfs()
print(ans)
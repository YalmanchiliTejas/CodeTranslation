N,M = map(int,input().split())
ad = [[] for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    a -= 1; b -= 1
    ad[a].append(b)
    ad[b].append(a)

ans = 0

def dfs(v=0,visited=[0]*N):
    visited[v] = 1
    if all(visited):
        global ans
        ans += 1
        return
    for nv in ad[v]:
        if visited[nv] == 1: continue
        dfs(nv,visited[:])

dfs()
print(ans)
N,M = map(int,input().split())
ad = [[0]*N for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    a -= 1; b -= 1
    ad[a][b] = 1
    ad[b][a] = 1

ans = 0

def dfs(v=0,d=0,visited=[1]+[0]*(N-1)):
    if d == N-1:
        global ans
        ans += 1
        return
    for nv, bit in enumerate(ad[v]):
        if bit == 0: continue
        if visited[nv] == 1: continue
        visited[nv] = 1
        dfs(nv,d+1)
        visited[nv] = 0

dfs()
print(ans)
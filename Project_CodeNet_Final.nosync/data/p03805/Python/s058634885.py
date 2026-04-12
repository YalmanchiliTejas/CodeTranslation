N,M=map(int,input().split())

G=[[] for _ in range(N+1)]

for i in range(M):
  a,b=map(int,input().split())
  G[a].append(b)
  G[b].append(a)
  
ans=0

def dfs(v,seen=None,h=[]):
    global ans
    if not seen:
      seen = [0]*(N+1)
    seen[v] = 1
    if len(h) == N:
        ans += 1
        return
    update=0
    for u in G[v]:
        if seen[u] == 0:
          seen[u] = 1
          h.append(u)
          update = 1
          dfs(u,seen,h)
          h.pop()
          seen[u] = 0
    if update==0:return

dfs(1,h=[1])
print(ans)
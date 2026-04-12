import sys 
sys.setrecursionlimit(1000000)
N, M = map(int, input().split())
ab = [list(map(lambda x:int(x)-1, input().split())) for _ in range(M)]
adlist = [[] for _ in range(N)]
for a, b in ab:
  adlist[a] += [b] 
  adlist[b] += [a] 


used = [0]*N 
global ans 
ans = 0
def dfs(v):
  global ans 
  used[v] = 1 
  if sum(used) == N:
    ans += 1 
    return 

  for u in adlist[v]:
    if used[u] == 0:
      used[u] = 1 
      dfs(u)
      used[u] = 0  

  return 

dfs(0)
print(ans)
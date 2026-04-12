import sys 
sys.setrecursionlimit(1000000)
n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x:int(x)-1, input().split())
  graph[a] += [b]
  graph[b] += [a]

used = [0]*n
global ans 
ans = 0
def dfs(u):
  global ans
  used[u] = 1
  if sum(used) == n:
    ans += 1
    return 
  
  for v in graph[u]:
    if used[v] == 0:
      used[v] = 1
      dfs(v)
      used[v] = 0 

  return 

dfs(0)
print(ans)

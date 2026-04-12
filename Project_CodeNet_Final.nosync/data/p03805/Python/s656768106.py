N, M = map(int,input().split())
C = [[] for i in range(N)]
for i in range(M):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  C[a].append(b)
  C[b].append(a)
visited = [0]*N
ans = 0
def dfs(x):
  global ans
  visited[x] = 1  
  if all(visited):
    ans += 1
    return
  for i in C[x]:
    if visited[i] == 0:
      dfs(i)
      visited[i] = 0
  return
dfs(0)
print(ans)
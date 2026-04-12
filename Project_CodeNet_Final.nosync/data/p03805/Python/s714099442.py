n, m = map(int, input().split())
e = [[False]*n for _ in range(n)]
for m in range(m):
  a, b = map(int, input().split())
  e[a-1][b-1] = True
  e[b-1][a-1] = True
visited = [False for _ in range(n)]

ans = 0

def dfs(v):
  global ans

  if all(visited):
    ans += 1
    return
  
  for i in range(n):
    if e[v][i] == False:
      continue
    if visited[i] == True:
      continue

    visited[i] = True
    dfs(i)
    visited[i] = False

visited[0] = True
dfs(0)
print(ans)
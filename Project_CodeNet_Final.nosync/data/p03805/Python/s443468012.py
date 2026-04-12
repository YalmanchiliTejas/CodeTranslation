N ,M = list(map(int, input().split()))
path = [[0]*N for i in range(N)]
visited = [0]*N
visited[0]=1
ans = 0
for i in range(M):
  a, b = list(map(int, input().split()))
  path[a-1][b-1]=1
  path[b-1][a-1]=1
  
def solve(i):
  global ans
  if not 0 in visited:
    ans += 1
    return
  else:
    for j in range(N):
      if path[i][j]==1 and visited[j] == 0:
        visited[j] = 1
        solve(j)
        visited[j] = 0
    return

solve(0)
print(ans)

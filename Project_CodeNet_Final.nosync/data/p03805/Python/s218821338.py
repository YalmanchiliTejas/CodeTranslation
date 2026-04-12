N, M = map(int, input().split())
E = [[0] * N for i in range(N)] 
for i in range(M):
  a_i, b_i = map(int, input().split())
  a_i = a_i - 1
  b_i = b_i - 1
  E[a_i][b_i] = 1
  E[b_i][a_i] = 1

visited = [0]*N

def dfs(n, depth):
  if visited[n]: # already visited
    return 0
  
  if depth == N:
    return 1
  
  visited[n] = 1
  
  ans = 0
  for next_n in range(N):
    if E[n][next_n]:
      ans += dfs(next_n, depth+1)
  
  visited[n] = 0
  return ans

print(dfs(0,1))
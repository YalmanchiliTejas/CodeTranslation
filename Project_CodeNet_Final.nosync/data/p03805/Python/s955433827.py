N, M = map(int, input().split())
adj = [[] for _ in range(N)]
for _ in range(M):
  i,j = map(int, input().split())
  adj[i-1].append(j-1)
  adj[j-1].append(i-1)

ans = 0
def dfs(path):
  if len(path) == N:
    global ans
    ans += 1
  for next in adj[path[-1]]:
    if next not in path:
      dfs(path+[next])
dfs([0])
print(ans)
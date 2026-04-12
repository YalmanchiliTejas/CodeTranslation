import sys
sys.setrecursionlimit(100000)

N, M = map(int, input().split())
adj = [[] for _ in range(N)]
visited = [0] * N

for i in range(M):
  a, b = map(int, input().split())
  adj[a-1].append(b)
  adj[b-1].append(a)

ans = []

def dfs(x):
  visited[x-1] = 1
  if visited == [1] * N:
    ans.append(1)
  for i in range(len(adj[x-1])):
    if visited[adj[x-1][i] - 1] == 0:
      dfs(adj[x-1][i])
  visited[x-1] = 0
      
dfs(1)
if ans == []:
  print(0)
else:
  print(sum(ans))
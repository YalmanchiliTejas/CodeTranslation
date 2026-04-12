N, M = map(int,input().split())
G = [[] for _ in range(N)]
for i in range(M):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  G[a].append(b)
  G[b].append(a)

visited = [True]*N
visited_all = [False]*N
cnt = [0]

def dfs(visited, pos):
  visited[pos] = False
  if visited == visited_all:
    cnt[0] += 1
  else:
    for p in G[pos]:
      if visited[p] == False:
        continue
      dfs(visited, p)
      visited[p] = True

dfs(visited, 0) 
print(cnt[0]) 
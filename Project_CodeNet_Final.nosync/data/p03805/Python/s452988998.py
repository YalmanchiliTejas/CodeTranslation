from collections import deque

N, M = map(int,input().split())
edge = [[] for i in range(N)]
visited = [0]
count = 0

for i in range(M):
  a, b = map(int,input().split())
  edge[a-1].append(b-1)
  edge[b-1].append(a-1)
  
def DFS(n):
  global count
  if len(visited) == N:
    count += 1
    return
  else:
    for i in edge[n]:
      if not(i in visited):
        visited.append(i)
        DFS(i)
        visited.remove(i)
    return

DFS(0)

print(count)
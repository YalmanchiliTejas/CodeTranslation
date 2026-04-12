#DFS
from collections import deque

N, M = map(int, input().split())
G = [[] for _ in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  G[a-1].append(b-1)
  G[b-1].append(a-1)
  
stack = deque([(0, 0)])
visited = [0] * N
depth = 0
ans = 0
while stack:
  now, depth = stack.pop()
  if depth == N-1:
    ans += 1
    continue
  visited[depth] = now
  for nxt in G[now]:
    if nxt not in visited[:depth+1]:
      stack.append((nxt, depth+1))
    
print(ans)
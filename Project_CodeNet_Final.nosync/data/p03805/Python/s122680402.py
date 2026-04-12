import sys
readline = sys.stdin.readline

N,M = map(int,readline().split())
G = [[] for i in range(N)]

for i in range(M):
  a,b = map(int,readline().split())
  G[a-1].append(b-1)
  G[b-1].append(a-1)
  
ans = 0
stack = []
stack.append([0,set()])
while stack:
  v,visited = stack.pop()
  if v in visited:
    continue
  visited2 = visited.copy()
  visited2.add(v)
  if len(visited2) == N:
    ans += 1
    continue
  for child in G[v]:
    stack.append([child,visited2])

print(ans)
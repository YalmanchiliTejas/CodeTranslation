
import sys
input = sys.stdin.readline
n = int(input())
ab = [list(map(int,input().split())) for i in range(n-1)]
graph = [[] for i in range(n+1)]
deg = [0]*(n+1)
for a,b in ab:
  graph[a].append(b)
  graph[b].append(a)
  deg[a] += 1
  deg[b] += 1
if n == 2:
  print("Second")
  exit()
stack = []
root = 0
for i in range(1,n+1)[::-1]:
  if deg[i] == 1:
    stack.append(i)
  else:
    root = i
flg = 0
deg[root] += 1
dp = [[] for i in range(n+1)]
dist = [-1]*(n+1)
while stack:
  x = stack.pop()
  if dp[x]:
    if dp[x].count(0)>=2:
      flg = 1
    if dp[x].count(0):
      dist[x] = 1
    else:
      dist[x] = 0
  else:
    dist[x] = 0
  for y in graph[x]:
    if deg[y] >= 2:
      dp[y].append(dist[x])
      deg[y] -= 1
      if deg[y] == 1:
        stack.append(y)
if flg or dist[root]==0:
  print("First")
else:
  print("Second")


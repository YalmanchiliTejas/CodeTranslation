# -*- coding: utf-8 -*-


N,M = map(int, input().split())
graph = [set() for _ in range(N)]
for _ in range(M):
  a,b = map(int, input().split())
  graph[a-1].add(b-1)
  graph[b-1].add(a-1)

ans = 0

def dfs(p, visited):
  global ans
  if len(visited) == N:
    ans += 1
  else:
    for q in graph[p]:
      if q not in visited:
        dfs(q, visited+[q])

dfs(0,[0])
print(ans)
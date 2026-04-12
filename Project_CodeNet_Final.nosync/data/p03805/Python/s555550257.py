# -*- coding: utf-8 -*-


N,M = map(int, input().split())
graph = [set() for _ in range(N)]
for _ in range(M):
  a,b = map(int, input().split())
  graph[a-1].add(b-1)
  graph[b-1].add(a-1)


def dfs(p, visited):
  if len(visited) == N:
    return 1
  else:
    ret = 0
    for q in graph[p]:
      if q not in visited:
        ret += dfs(q, visited+[q])
    return ret

print(dfs(0,[0]))

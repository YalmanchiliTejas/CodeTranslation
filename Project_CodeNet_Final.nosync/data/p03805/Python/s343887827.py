# -*- coding: utf-8 -*-

def dfs(v, N, visited):
  for i in range(1,N+1):
    if not visited[i]: break
    # すでに全て到達済みだったら
    if i == N: return 1

  ret = 0
  for i in range(1, N+1):
    if not graph[v][i]: continue
    if visited[i]: continue

    visited[i] = 1
    ret += dfs(i, N, visited)
    visited[i] = 0

  return ret

N,M = map(int, input().split())

graph = [[0]*(N+1) for i in range(N+1)]

for _ in range(0,M):
  a,b = map(int, input().split())
  graph[a][b] = 1
  graph[b][a] = 1

visited = [0] + [0 for _ in range(N)]

visited[1] = 1
print(dfs(1, N, visited))
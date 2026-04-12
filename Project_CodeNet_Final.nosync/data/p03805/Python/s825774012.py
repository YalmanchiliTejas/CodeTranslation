#深さ優先探索
N, M = map(int,input().split())
graph = [[] for j in range(N)]
for i in range(M):
  a, b = map(int,input().split())
  graph[a-1].append(b-1)
  graph[b-1].append(a-1)
judge = [False]*N
judge[0] = True

def dfs(v,judge):#vは今いる場所
  if all(judge):
    return 1
  res = 0
  for nv in graph[v]:#vと隣り合っている場所
    if judge[nv]:#すでに探索済み
      continue #if文の初めに戻る
    judge[nv] = True
    res += dfs(nv,judge)
    judge[nv] = False
  return res
print(dfs(0,judge))

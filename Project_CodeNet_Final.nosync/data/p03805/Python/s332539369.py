from collections import deque

def dfs(G, visited, s, n, ans):
  # すべての頂点を訪れた場合の処理
  if all(visited) :
    ans += 1
    return ans
  #　次の頂点の探索
  for i in range(n) :
    if visited[i] == False and (G[s][i] == 1 or G[i][s] == 1) :
      visited[i] = True
      ans = dfs(G, visited, i, n, ans)
      visited[i] = False
  return ans

#　グラフGの入力
n,m = map(int,input().split())
G = [[0 for i in range(n)] for j in range(n)]
for i in range(m) :
  a,b = map(int,input().split())
  G[a-1][b-1] = 1
  G[b-1][a-1] = 1
  

visited = [False for i in range(n)]
visited[0] = True
ans = 0
print(dfs(G, visited, 0, n, ans))
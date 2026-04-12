import numpy as np
nmax = 8
graph = np.array([[False]*nmax]*nmax)
 
n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = True
    
visited = [False]*nmax
visited[0] = True
 
def dfs(v, n, visited): # v：今訪れた頂点
    all_visited = True
    for i in range(n):
        if visited[i] == False:
            all_visited = False
 
    if all_visited:
        return 1 #1通り
    
    ret = 0 #最初は0通り
    
    for i in range(n):
        if graph[v][i] == False: #vからiに行けない場合は除外
            continue
        if visited[i]: #iを訪問済みだったら行かない
            continue
        
        visited[i] = True #vからiに訪問
        ret += dfs(i, n, visited) #今iにいる時の次の動作
        visited[i] = False #iではないところにいくケース
        
    return ret
  
print(dfs(0, n, visited))
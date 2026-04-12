n,m=map(int,input().split())
#隣接リスト
graph=[[0]*n for _ in range(n)]
for _ in range(m):
  a,b=map(int,input().split())
  graph[a-1][b-1]=1
  graph[b-1][a-1]=1


def dfs(v,visited):
  #print("v",v,"visited",visited)
  if not False in visited:
    #print("visited",visited,"end")
    return 1
  count=0
  for i in range(n):
    if not graph[v][i]:continue
    if visited[i]:continue
    
    visited[i]=True
    count+=dfs(i,visited)
    visited[i]=False
  return count

# 到達したかどうかlist（Falseは未到達、Trueは到達済み）
visited=[False] *(n)
visited[0]=True
print(dfs(0,visited))
#print("visited",visited)
#print("graph",graph)

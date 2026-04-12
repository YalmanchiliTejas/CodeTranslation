def dfs(n,v,graph,visited):
  all_visited=True
  
  for i in range(n):
    if visited[i]==False:
      all_visited=False
      
  if all_visited==True:
    return 1
  
  ret=0
  for i in range(len(graph[v])):
    if visited[graph[v][i]]==False:
    	visited[graph[v][i]]=True
    	ret += dfs(n,graph[v][i],graph,visited)
    	visited[graph[v][i]]=False
  return ret

n,m=list(map(int,input().split()))

visited=[]
for j in range(n):
  visited.append(False)

graph=[]
for j in range(n):
  graph.append([])
  
for j in range(m):
  a,b=list(map(int,input().split()))
  graph[a-1].append(b-1)
  graph[b-1].append(a-1)

visited[0]=True

print(dfs(n,0,graph,visited))
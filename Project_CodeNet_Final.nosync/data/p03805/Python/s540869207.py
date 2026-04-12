N,M = map(int,input().split())
Branch = [list(map(int,input().split())) for i in range(M)]
Visited = [0 for i in range(N)]
Visited[0] = 1
Glaph = [[0 for i in range(N)] for i in range(N)] 
for b in Branch:
  Glaph[b[0]-1][b[1]-1] = 1; Glaph[b[1]-1][b[0]-1] = 1
def dfs(v,N,Visited):
  flag = True
  for i in range(N):
    if Visited[i] == 0:
      flag = False
  if flag:
    return 1
  
  ret = 0
  
  for i in range(N):
    if Glaph[v][i] == False: continue
    if Visited[i]: continue    
    Visited[i] = 1    
    ret+=dfs(i,N,Visited)
    Visited[i]= 0
  return ret

print(dfs(0,N,Visited ))
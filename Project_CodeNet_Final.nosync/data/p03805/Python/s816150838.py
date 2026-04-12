graph=[[False for i in range(8)]for j in range(8)]
def dfs(x,N,visted):
 all=True
 for i in range(N):
  if(visted[i]==False):
    all=False
 if all==True:
  return 1

 ret=0
 for i in range(N):
   if graph[x][i]==False:
    continue
   if visted[i]==True:
    continue
   visted[i]=True
   ret=ret+dfs(i,N,visted)
   visted[i]=False
  
 return ret

N,M=map(int,input().split())
for i in range(M):   
  x,y=map(int,input().split())
  graph[x-1][y-1]=True
  graph[y-1][x-1]=True
visted=[False for i in range(N)]
visted[0]=True
print(dfs(0,N,visted))
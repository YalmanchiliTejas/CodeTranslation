import numpy as np
n,m=map(int,input().split())
info=np.zeros((n,n),dtype=int)

for i in range(m):
  a,b=map(int,input().split())
  info[a-1][b-1]=1
  info[b-1][a-1]=1

  
def f(v,visit):
  cnt=0
  ff=1
  for i in range(n):
    if visit[i]==0:
      ff=0
  if ff==1:
    return 1
  
  for i in range(n):
    if info[v][i]==1 and visit[i]==0:
      visit[i]=1
      cnt+=f(i,visit)
      visit[i]=0
    
  return cnt
  
visit=np.zeros(n,dtype=int)
visit[0]=1

print(f(0,visit))

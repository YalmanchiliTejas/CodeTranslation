from heapq import heappush,heappop
N=int(input())
X,Y=[],[]
for i in range(N):
  x,y=map(int,input().split())
  X.append((x,i))
  Y.append((y,i))
X.sort()
Y.sort()
inf=float("inf")
G=[[]*N for i in range(N)]
for i in range(N-1):
  G[X[i][1]].append((X[i+1][0]-X[i][0],X[i+1][1]))
  G[X[i+1][1]].append((X[i+1][0]-X[i][0],X[i][1]))
  G[Y[i][1]].append((Y[i+1][0]-Y[i][0],Y[i+1][1]))
  G[Y[i+1][1]].append((Y[i+1][0]-Y[i][0],Y[i][1]))
  
Q=[(0,0)]
ans=0
visited=[False]*N
while Q:
  c,n=heappop(Q)
  if visited[n]:
    continue
  visited[n]=True
  ans+=c
  for c2,n2 in G[n]:
    if visited[n2]:
      continue
    else:
      heappush(Q,(c2,n2))

print(ans)

                
              
              
  

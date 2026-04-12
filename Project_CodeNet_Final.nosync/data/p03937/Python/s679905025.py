from collections import deque

h,w=map(int,input().split())
l=[]
c=0
for i in range(h):
 t_l=list(input())
 c+=t_l.count('#')
 l.append(t_l)

sy,sx=0,0
gy,gx=h-1,w-1

dist=[[-1]*w for i in range(h)]
dist[0][0]=0

que=deque()
que.append((sy,sx))

while que:
 y,x=que.popleft()

 if y==gy and x==gx and dist[gy][gx]==c-1:
  print('Possible')
  exit()

 for dy,dx in [[1,0],[0,1]]:
  ny=y+dy
  nx=x+dx
  if ny<=h-1 and nx<=w-1 and l[ny][nx]=='#' and dist[ny][nx]==-1:
   que.append((ny,nx))
   l[ny][nx]=='.'
   dist[ny][nx]=dist[y][x]+1

print('Impossible')
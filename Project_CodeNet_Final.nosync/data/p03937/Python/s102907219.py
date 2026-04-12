from collections import deque
h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
def BFS(x,y):
  flag=False
  qu=deque([])
  qu.append([x,y])
  
  while len(qu)!=0:
    d=qu.popleft()
    now_x,now_y=d[0],d[1]
    #print(now_x,now_y)
    #print(now_x==w-1 and now_y==h-1)
    a[now_y][now_x]="."
    if now_x==w-1 and now_y==h-1:
      flag=True
      return flag
      
    if now_y<h-1 and a[now_y+1][now_x]=="#":
      qu.append([now_x,now_y+1])
    if now_x<w-1 and a[now_y][now_x+1]=="#":
      qu.append([now_x+1,now_y])
    if now_y<h-1 and a[now_y+1][now_x]=="#" and now_x<w-1 and a[now_y][now_x+1]=="#":
      return flag
  return flag
flag=BFS(0,0)
for i in a:
  for j in i:
    if j=="#":
      flag=False
if flag:
  print("Possible")
else:
  print("Impossible")
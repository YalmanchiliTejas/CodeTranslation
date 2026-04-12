h,w=map(int,input().split())
s=[input() for _ in range(h)]
v=[[1]*w for _ in range(h)]
q=[(0,0)]
dxy=((-1,0),(0,-1),(1,0),(0,1))
while q:
  x,y=q.pop()
  v[x][y]=0
  cnt=0
  for dx,dy in dxy:
    nx=x+dx
    ny=y+dy
    if not(0<=nx<h and 0<=ny<w) or s[nx][ny]=='.':continue
    elif v[nx][ny] and ((dx==-1 or dy==-1)or cnt):
      print('Impossible')
      exit()
    elif v[nx][ny] :
      q+=[(nx,ny)]
      cnt=1
print(['Possible','Impossible'][v[h-1][w-1]])
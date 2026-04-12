def dask(x,y):
  if(a[x][y]=="."):
    return [0,0,False]
  if(a[x+1][y]=="#"):
    for i in range(w):
      if(i>y and a[x][i]=="#"):
        return [0,0,False]
    return [x+1,y,True]
  if(a[x][y+1]=="#"):
    for i in range(h):
      if(i>x and a[i][y]=="#"):
        return [0,0,False]
    return [x,y+1,True]
  return [0,0,False]
h,w=map(int,input().split())
a=[input()+"." for _ in[0]*h]+["."*(w+1)]
x=0
y=0
fl=True
while(fl and (x<h-1 or y<w-1)):
  x,y,fl=dask(x,y)
print("Possible" if fl else "Impossible")
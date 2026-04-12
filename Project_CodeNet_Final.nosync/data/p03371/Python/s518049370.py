a,b,c,x,y = map(int,input().split())
fx = x
fy = y
fl = 0
val = int(0)
fmin = min(x,y)
if a>2*c:
  x = 0
  y = y - fx
  val += 2*c*fx
  fl += 1
if y < 0:
  y = 0
if b>2*c:
  if fl == 1:
    val += 2*c*y
    y = 0
  else:
    val += 2*c*y
    x = x -y
    y = 0 
if x < 0:
  x = 0
nx = x
ny = y
if a+b>2*c:
  x = x - min(nx,ny)
  y = y - min(nx,ny)
  val += 2*c*min(nx,ny)
print(val+a*x+b*y)
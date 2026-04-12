import sys
a,b,c,x,y=map(int,input().split())
val=0
if a+b<=2*c:
  print(a*x+b*y)
  sys.exit()
else:
  m=min(x,y)
  val+=m*c*2
  x=x-m
  y=y-m
  if x==0:
    if y==0:
      print(val)
      sys.exit()
    val+=min(b*y,y*2*c)
  if y==0:
    val+=min(a*x,x*2*c)
  print(val)
  sys.exit()

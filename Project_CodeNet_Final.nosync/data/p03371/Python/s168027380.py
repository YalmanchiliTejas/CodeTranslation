a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
  print(a*x+b*y)
else:
  if x>=y:
    total=y*2*c
    if a*(x-y)>=2*c*(x-y):
      total+=2*c*(x-y)
    else:
      total+=a*(x-y)
  else:
    total=x*2*c
    if b*(y-x)>=c*2*(y-x):
      total+=2*c*(y-x)
    else:
      total+=b*(y-x)
  print(total)
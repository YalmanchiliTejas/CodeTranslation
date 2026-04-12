a,b,c,x,y=map(int,input().split())
if a+b<2*c:
  print(a*x+b*y)
else:
  if x>y:
    print(min(2*c*y+a*(x-y),2*c*x))
  else:
    print(min(2*c*x+b*(y-x),2*c*y))
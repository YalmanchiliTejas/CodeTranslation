a,b,c,x,y=map(int,input().split())
cost=0
if a+b<=2*c:
  print(a*x+b*y)
else:
  if x>y:
    cost+=2*y*c
    if a>2*c:
      print(cost+2*c*(x-y))
    else:
      print(cost+a*(x-y))
  else:
    cost+=2*x*c
    if b>2*c:
      print(cost+2*c*(y-x))
    else:
      print(cost+b*(y-x))
    
  
a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
  print(a*x+b*y)
else:
  total=2*c*min(x,y)
  if x<=y:
    if b<=2*c:
      print(total+b*(y-x))
    else:
      print(total+2*c*(y-x))
  else:
    if a<=2*c:
      print(total+a*(x-y))
    else:
      print(total+2*c*(x-y))
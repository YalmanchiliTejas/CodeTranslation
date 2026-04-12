a,b,c,x,y = map(int, input().split())

if a+b <= c*2:
  print(a*x+b*y)
else:
  if x == y: print(c*x*2)
  elif x > y: 
    if a <= c*2: print(c*y*2+a*(x-y))
    else: print(c*x*2)
  elif x < y: 
    if b <= c*2: print(c*x*2+b*(y-x))
    else: print(c*y*2)
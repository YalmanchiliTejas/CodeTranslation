a,b,c,x,y = map(int, input().split())

if (a+b) > c*2:
  tmp = min(x,y)
  if x > y:
    print(min(c*2*tmp + a*(x-y), c*2*x))
  else:
    print(min(c*2*tmp + b*(y-x), c*2*y))
else:
  print(a*x + b* y)
  
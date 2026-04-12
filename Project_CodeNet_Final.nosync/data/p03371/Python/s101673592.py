a,b,c,x,y = map(int,input().split())
if 2*c-a-b >= 0:
  print(a*x+b*y)
else:
  s = 0
  if x >= y:
    s += 2*c*y
    x -= y
    s += min(2*c,a)*x
    print(s)
  else:
    s += 2*c*x
    y -= x
    s += min(2*c,b)*y
    print(s)
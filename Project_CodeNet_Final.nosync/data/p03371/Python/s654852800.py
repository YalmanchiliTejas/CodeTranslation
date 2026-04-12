a,b,c,x,y = (int(i) for i in input().split())
if a+b > c*2:
  if x > y:
    print(c*min(x,y)*2 + (x-y) * min(a, c*2))
  else:
    print(c*min(x,y)*2 + (y-x) * min(b, c*2))
else:
  print(a*x + b*y)
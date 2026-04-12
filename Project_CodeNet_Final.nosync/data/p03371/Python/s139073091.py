a,b,c,x,y=map(int,input().split())
if c*2<=a and c*2<=b:
  print(c*2*max(x,y))
  exit()
if c*2<=a:
  print(c*2*x+max(0,b*(y-x)))
  exit()
if c*2<=b:
  print(c*2*y+max(0,a*(x-y)))
  exit()
if c*2>=a+b:
  print(a*x+b*y)
  exit()
if x>=y:
  print(2*c*y+(x-y)*a)
else:
  print(2*c*x+(y-x)*b)
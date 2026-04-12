import math
a,b,ab,x,y = map(int,input().split())

if a+b<2*ab:
  print(a*x+b*y)
else:
  amount = min(min(x,y)*2*ab+ (abs(x-y))*(a if x>y else b),max(x,y)*2*ab)
  print(amount)
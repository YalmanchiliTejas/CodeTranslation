a,b,c,x,y=map(int,input().split())

c *= 2

MIN=10**9

tmp = a*x + b*y
if tmp < MIN: MIN=tmp
  
if x <= y:
  tmp = c*x + (y-x)*b
  if tmp < MIN: MIN=tmp

else:
  tmp = c*y + (x - y)*a
  if tmp < MIN: MIN=tmp

tmp = c*max(x,y)
if tmp < MIN: MIN=tmp
  
print(MIN)
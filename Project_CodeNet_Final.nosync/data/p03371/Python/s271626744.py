a,b,c,x,y = map(int,input().split())
if x <= y:
  M = y
  m = x
  Mp = b
  mp = a
else:
  M = x
  m = y
  Mp = a
  mp = b
print(min(a*x+b*y,2*m*c+(M-m)*Mp,2*M*c))
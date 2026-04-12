A,B,C,X,Y = map(int, input().split())
pmin = 10**9
for i in range(max([X,Y])+1):
  x = X-i if X-i>0 else 0
  y = Y-i if Y-i>0 else 0
  p = A*x + B*y + 2*C*i
  pmin = min(pmin,p)
  
print(pmin)
A,B,C,X,Y = map(int,input().split())

if X > Y:
  D = A
else:
  D = B
  
if A+B < 2*C:
  print(A*X + B*Y)
elif D < 2*C:
  print(2*C*min(X,Y) + D*abs(X-Y))
else:
  print(2*C*max(X,Y))
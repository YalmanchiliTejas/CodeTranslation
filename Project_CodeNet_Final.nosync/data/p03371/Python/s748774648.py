A,B,C_AB,X,Y = map(int, input().split())
if A+B >= 2*C_AB:
  print(2*C_AB*(min(X,Y)) + min(A,2*C_AB)*(X-min(X,Y)) + min(B,2*C_AB)*(Y-min(X,Y)))
else:
  print(A*X+ B*Y)

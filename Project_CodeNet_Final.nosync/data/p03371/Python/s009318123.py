A,B,C,X,Y = map(int, input().split())

if X <= Y:
  S = B
  Z = X
  W = Y
else:
  S = A
  Z = Y
  W = X
  
if 2*C > A+B:
  print(A*X+B*Y)

elif 2*C > S:
  print((2*C-S)*Z + S*W)
  
else:
  print(2*C*W)
  
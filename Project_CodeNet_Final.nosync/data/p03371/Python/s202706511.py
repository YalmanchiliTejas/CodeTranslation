import sys
A, B, C, X, Y = map(int, input().split())
if 2*C >= A+B:
  print(A * X + B * Y)
  
else:
  if Y > X:
    X, Y = Y, X
    A, B = B, A
  print(2*C * Y + (X-Y)*min(2*C, A))
  
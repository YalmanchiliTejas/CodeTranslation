import numpy as np

A, B, C, X,Y = map(int,input().split())

m = min(X,Y)
p = np.abs(X-Y)

A_B_only = A*X+B*Y
A_B = A*m+B*m+p*2*C

if X<Y:
  AB = m*2*C+p*B
  AB_only = Y*2*C
elif Y<X:
  AB = m*2*C+p*A
  AB_only = X*2*C
elif X==Y:
  AB = m*2*C
  AB_only = X*2*C


print(min(A_B,AB,AB_only,A_B_only))
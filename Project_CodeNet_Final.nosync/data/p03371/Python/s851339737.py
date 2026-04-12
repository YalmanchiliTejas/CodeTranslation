A, B, C, X, Y = input().split(' ')
A = int(A)
B = int(B)
C = int(C)
X = int(X)
Y = int(Y)
if A > 2*C:
  A = 2*C
if B > 2*C:
  B = 2*C
if A + B <= 2*C:
  print(A*X+B*Y)
else:
  if X > Y:
    sum = (X-Y)*A + Y*2*C
  else:
    sum = (Y-X)*B + X*2*C
  print(sum)
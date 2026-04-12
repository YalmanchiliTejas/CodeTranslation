A,B,C,X,Y = (input().split())

A = int(A)
B = int(B)
C = int(C)
X = int(X)
Y = int(Y)



value = 0

na = 0
nb = 0
nc = 0


if A+B <= 2*C:
  value = X * A + Y * B
else:
  if X > Y:
    if 2*C <= A:
      nc = 2*X
    else:
      na = X - Y
      nc = 2*Y
  else:
    if 2*C <= B:
      nc = 2*Y
    else:
      nb = Y - X
      nc = 2*X
  value = A * na + B * nb + C * nc

print(value)
  
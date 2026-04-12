A, B, C, X, Y = map(int, input().split())

m = min([X,Y])
M = max([X,Y])
d = abs(X-Y)
if A+B < 2*C:
  res = X*A + Y*B
elif X < Y:
  if 2*C*X + B*(Y-X) < 2*C*Y:
    res = 2*C*X + B*(Y-X)
  else:
    res = 2*C*Y
else:
  if 2*C*Y + A*(X-Y) < 2*C*X:
    res = 2*C*Y + A*(X-Y)
  else:
    res = 2*C*X

print(res)
      
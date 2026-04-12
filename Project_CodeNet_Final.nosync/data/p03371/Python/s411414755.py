A, B, C, X, Y = map(int, input().split())
r1 = A*X+B*Y
if X < Y:
  r2 = 2*C*X+B*(Y-X)
else:
  r2 = 2*C*Y+A*(X-Y)
if X < Y:
  r3 = 2*C*Y
else:
  r3 = 2*C*X
r = min(r1, r2, r3)
print(r)

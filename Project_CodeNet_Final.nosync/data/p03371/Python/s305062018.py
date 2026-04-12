A,B,C,X,Y = map(int, input().split())
if A+B < 2*C:
  ans = A*X+B*Y
else:
  XY = min(X,Y)
  ans = min(A*(X-XY) + B*(Y-XY) + 2*C*XY, 2*C*max(X,Y))
print(ans)

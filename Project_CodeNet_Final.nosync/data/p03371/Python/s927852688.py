A, B, C, X, Y = map(int, input().split())
ans = X*A + Y*B
if X>Y:
  ans = min(X*A + Y*B, 2*X*C, 2*Y*C+(X-Y)*A)
else:
  ans = min(X*A + Y*B, 2*Y*C, 2*X*C+(Y-X)*B)
print(ans)
A, B, C, X, Y = map(int, input().split())
ans = 0
if A + B < 2 * C:
  print(A * X + B * Y)
else:
  while X > 0 and Y > 0:
    ans += 2 * C
    X -= 1
    Y -= 1  
  if A > 2 * C:
    A = 2 * C
  if B > 2 * C:
    B = 2 * C
  print(ans + A * X + B * Y)
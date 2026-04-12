A, B, C, X, Y = map(int, input().split())
minXY = min(X, Y)
if A + B >= 2 * C:#C2枚を買う方が良い
  ans = 2 * C *minXY
  X, Y = X - minXY, Y - minXY
  if X == 0:
    if B > 2 * C:
      ans += 2 * C * Y
    else:
      ans += B * Y
  else:# Y == 0
    if A > 2 * C:
      ans += 2 * C * X
    else:
      ans += A * X
else:#それぞれの方が安い
  ans = A * X + B * Y
  
print(ans)
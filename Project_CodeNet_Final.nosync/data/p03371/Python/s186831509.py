A, B, C, X, Y = list(map(int, input().split()))

Ans = 0
if A > C * 2:
  Ans += C * (X * 2)
  Y -= X
  X = 0
if B > C * 2:
  Ans += C * (Y * 2)
  X -= Y
  Y = 0
X = max(0, X)
Y = max(0, Y)
if A + B > C * 2:
  t = min(X, Y)
  Ans += C * (t * 2)
  X -= t
  Y -= t
if X > 0:
  Ans += A * X
if Y > 0:
  Ans += B * Y

print(Ans)
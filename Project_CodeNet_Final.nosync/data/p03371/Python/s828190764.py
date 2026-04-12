A, B, C, X, Y = map(int, input().split())
# X >= Yとしたい。
if X < Y:
  A, B = B, A
  X, Y = Y, X
else:
  pass
if A + B <= 2 * C:
  print(A * X + B * Y)
else:
    if A >= 2 * C:
      print(C * 2 * X)
    else:
      print(A * (X - Y) + C * 2 * Y)
      
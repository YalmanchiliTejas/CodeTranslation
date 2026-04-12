A, B, C, X, Y = [int(n) for n in input().split(" ")]

if X >= Y:
  print(min([X * A + Y * B, 2 * X * C, 2 * Y * C + (X - Y) * A]))
else:
  print(min([X * A + Y * B, 2 * Y * C, 2 * X * C + (Y - X) * B]))